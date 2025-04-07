import argparse


class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        start_idx = 0
        stop_idx = len(haystack)
        return haystack.find(needle, start_idx, stop_idx)


def main():
    parser = argparse.ArgumentParser(prog='Find the Index of the First Occurrence in a String: ' \
                                          'https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string')
    parser.add_argument('--strings', type=str, required=True,
                        help='Input two string (e.g. "sadbutsad sad")')

    args = parser.parse_args()
    haystack, needle = args.strings.split(' ')
    print(f'Haystack: {haystack}')
    print(f'Needle: {needle}')

    solution = Solution()
    res = solution.strStr(haystack, needle)

    if res != -1:
        print(f'Index of first occurence of {needle} in {haystack} is {res}')
    else: 
        print(f'{needle} does not occur in {haystack}')


if __name__ == "__main__":
    main()