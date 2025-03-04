from collections import deque
import argparse
import re

def parse_binary_tree(input: str):
    matches = re.findall(r'\d+|None', input)

    numbers = []
    for match in matches:
        if match == "None":
            numbers.append(None)
        else:
            numbers.append(int(match))

    print(f'Tree nums: {numbers}')
    return numbers


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = None
        self.right = None

    def insert(self, values):
        """(Made with DeepSeek) Constructs a binary tree from a list of values, skipping None."""
        if not values:
            return None

        # Create the root node
        self.val = values[0]
        queue = deque([self])
        idx = 1

        while queue and idx < len(values):
            node = queue.popleft()

            # Assign left child if value is not None
            if idx < len(values) and values[idx] is not None:
                node.left = TreeNode(values[idx])
                queue.append(node.left)
            idx += 1

            # Assign right child if value is not None
            if idx < len(values) and values[idx] is not None:
                node.right = TreeNode(values[idx])
                queue.append(node.right)
            idx += 1

    def print_tree(self):
        if self.left:
            self.left.print_tree()
        print(self.val),
        if self.right:
            self.right.print_tree()

    def display_tree(self, tree, level=0, prefix="Root: "):
        """(Made with DeepSeek) Recursively display the binary tree."""
        if tree is not None:
            print(" " * (level * 4) + prefix + str(tree.val))
            if tree.left is not None or tree.right is not None:
                self.display_tree(tree.left, level + 1, "L--- ")
                self.display_tree(tree.right, level + 1, "R--- ")
                
    def height_tree(self, tree) -> int:
        if tree is None:
            return -1
        
        return 1 + max(self.height_tree(tree.left), self.height_tree(tree.right))

def is_balanced_tree(root) -> bool:
    if root is None:
        return True

    left_height = root.height_tree(root.left)
    right_height = root.height_tree(root.right)

    if abs(left_height - right_height) > 1:
        print(f"Right: {right_height}, Left: {left_height}")
        return False

    return is_balanced_tree(root.left) and is_balanced_tree(root.right)


def main():
    parser = argparse.ArgumentParser(prog='Balanced Binary Tree problem: https://leetcode.com/problems/balanced-binary-tree')
    parser.add_argument('--tree', type=str, required=True,
                        help='Input string to find is Binary Tree balanced or not (e.g. [3, 9, 20, None, None, 15, 7])')

    args = parser.parse_args()
    binary_tree = parse_binary_tree(args.tree)

    # Start root of binary tree
    root = TreeNode()
    root.insert(binary_tree)

    root.display_tree(root)
    max_height = root.height_tree(root)
    print(f'Height of a tree {max_height}')

    res = is_balanced_tree(root)

    if res is True:
        print('Height Balanced')
    else:
        print('NOT Height Balanced')


if __name__ == "__main__":
    main()