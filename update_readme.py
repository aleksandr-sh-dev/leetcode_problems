#!/usr/bin/env python3
import os
import re
from pathlib import Path
from urllib.parse import quote

# Map repository language folders to display names and file extensions
LANGUAGE_CONFIG = {
    "c": ("C", {".c"}),
    "cpp": ("C++", {".cpp", ".cc", ".cxx"}),
    "python": ("Python", {".py"}),
    "rust": ("Rust", {".rs"}),
    "java": ("Java", {".java"}),
    "go": ("Go", {".go"}),
    "javascript": ("JavaScript", {".js"}),
    "typescript": ("TypeScript", {".ts"}),
}

DIFFICULTY_CONFIG = {
    "easy": ("🟢 Easy", 1),
    "medium": ("🟡 Medium", 2),
    "hard": ("🔴 Hard", 3),
}

# Special case overrides for filenames that differ slightly from LeetCode's URL slug or title
SPECIAL_OVERRIDES = {
    69: ("Sqrt(x)", "https://leetcode.com/problems/sqrtx/"),
    242: ("Valid Anagram", "https://leetcode.com/problems/valid-anagram/"),
}

# Words to keep lowercase/uppercase when auto-generating titles for brand-new files
LOWERCASE_WORDS = {
    "a",
    "an",
    "and",
    "as",
    "at",
    "but",
    "by",
    "for",
    "from",
    "in",
    "into",
    "of",
    "on",
    "or",
    "the",
    "to",
    "with",
}
UPPERCASE_WORDS = {"ii", "iii", "iv", "bst", "2d", "lru", "lfu"}


def format_title_from_slug(slug_words: list[str]) -> str:
    """Converts filename words like ['binary', 'tree', 'ii'] into 'Binary Tree II'."""
    titled = []
    for i, word in enumerate(slug_words):
        low = word.lower()
        if low in UPPERCASE_WORDS:
            titled.append(low.upper())
        elif i > 0 and i < len(slug_words) - 1 and low in LOWERCASE_WORDS:
            titled.append(low)
        elif low in {"3sum", "4sum"}:
            titled.append(low[0] + "Sum")
        else:
            titled.append(word.capitalize())
    return " ".join(titled)


def parse_existing_readme(readme_path: Path) -> dict[int, tuple[str, str]]:
    """
    Reads the existing README.md to preserve custom titles and LeetCode links
    for problems already in the table.
    """
    existing_metadata = {}
    if not readme_path.exists():
        return existing_metadata

    # Matches table rows: | 69 | [Sqrt(x)](https://leetcode.com/problems/sqrtx/) | ...
    row_pattern = re.compile(r"^\|\s*(\d+)\s*\|\s*\[([^\]]+)\]\(([^)]*)\)\s*\|")
    with readme_path.open("r", encoding="utf-8") as f:
        for line in f:
            match = row_pattern.match(line.strip())
            if match:
                prob_id = int(match.group(1))
                title = match.group(2).strip()
                url = match.group(3).strip()
                existing_metadata[prob_id] = (title, url)

    return existing_metadata


def scan_repository(root_dir: Path, existing_meta: dict[int, tuple[str, str]]):
    """
    Scans language and difficulty folders and collects all problem solutions.
    """
    problems = {}
    file_pattern = re.compile(r"^(\d+)[_.\s-]+(.+)$")

    for lang_folder, (lang_name, valid_exts) in LANGUAGE_CONFIG.items():
        lang_dir = root_dir / lang_folder
        if not lang_dir.is_dir():
            continue

        for diff_folder, (diff_label, _) in DIFFICULTY_CONFIG.items():
            diff_dir = lang_dir / diff_folder
            if not diff_dir.is_dir():
                continue

            for file_path in sorted(diff_dir.rglob("*")):
                if not file_path.is_file() or file_path.suffix not in valid_exts:
                    continue

                stem = file_path.stem
                match = file_pattern.match(stem)
                if not match:
                    continue

                prob_id = int(match.group(1))
                raw_name = match.group(2)
                words = [w for w in re.split(r"[_\s-]+", raw_name) if w]

                # 1. Determine Title and LeetCode URL
                if prob_id in SPECIAL_OVERRIDES:
                    title, url = SPECIAL_OVERRIDES[prob_id]
                elif prob_id in existing_meta and existing_meta[prob_id][1]:
                    title, url = existing_meta[prob_id]
                else:
                    slug = "-".join(w.lower() for w in words)
                    url = f"https://leetcode.com/problems/{slug}/"
                    title = format_title_from_slug(words)

                # Relative path with URL-encoded spaces if any
                rel_path = file_path.relative_to(root_dir).as_posix()
                encoded_rel_path = "./" + quote(rel_path, safe="/_.-")

                if prob_id not in problems:
                    problems[prob_id] = {
                        "id": prob_id,
                        "title": title,
                        "url": url,
                        "difficulty_key": diff_folder,
                        "difficulty_label": diff_label,
                        "solutions": [],
                    }

                problems[prob_id]["solutions"].append((lang_name, encoded_rel_path))

    return problems


def generate_readme(problems: dict, readme_path: Path):
    """Generates and writes the formatted README.md file."""
    stats = {
        "easy": {"unique": 0, "files": 0},
        "medium": {"unique": 0, "files": 0},
        "hard": {"unique": 0, "files": 0},
    }

    sorted_ids = sorted(problems.keys())

    for pid in sorted_ids:
        prob = problems[pid]
        d_key = prob["difficulty_key"]
        num_files = len(prob["solutions"])
        stats[d_key]["unique"] += 1
        stats[d_key]["files"] += num_files

    total_unique = sum(s["unique"] for s in stats.values())
    total_files = sum(s["files"] for s in stats.values())

    lines = [
        "# LeetCode Solutions",
        "",
        "This repository contains implementations, algorithms and data structures practice across various topics, languages, and difficulty levels.",
        "",
        "## 📊 Progress Overview",
        "",
        "| Difficulty | Unique Problems Solved | Total Solution Files |",
        "| :--- | :---: | :---: |",
        f"| 🟢 Easy | {stats['easy']['unique']} | {stats['easy']['files']} |",
        f"| 🟡 Medium | {stats['medium']['unique']} | {stats['medium']['files']} |",
        f"| 🔴 Hard | {stats['hard']['unique']} | {stats['hard']['files']} |",
        f"| **Total** | **{total_unique}** | **{total_files}** |",
        "",
        "---",
        "",
        "## 📋 Solutions List",
        "",
        "| # | Problem | Difficulty | Solutions |",
        "| :-: | :--- | :---: | :--- |",
    ]

    for pid in sorted_ids:
        prob = problems[pid]
        # Sort solutions alphabetically by language name (C, C++, Python, Rust)
        sorted_sols = sorted(prob["solutions"], key=lambda x: x[0])
        sol_links = ", ".join(f"[{lang}]({path})" for lang, path in sorted_sols)
        lines.append(
            f"| {pid} | [{prob['title']}]({prob['url']}) | {prob['difficulty_label']} | {sol_links} |"
        )

    lines.append("")

    with readme_path.open("w", encoding="utf-8") as f:
        f.write("\n".join(lines))

    print(
        f"✅ README.md updated! ({total_unique} unique problems, {total_files} total files)"
    )


if __name__ == "__main__":
    repo_root = Path(__file__).resolve().parent
    readme_file = repo_root / "README.md"

    existing_data = parse_existing_readme(readme_file)
    all_problems = scan_repository(repo_root, existing_data)
    generate_readme(all_problems, readme_file)
