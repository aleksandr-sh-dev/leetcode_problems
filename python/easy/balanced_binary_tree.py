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

    def insert(self, val):
        queue = [self]  # Start from root
        while queue:
            node = queue.pop(0)
            if node.left is None:
                node.left = TreeNode(val)
                return
            else:
                queue.append(node.left)

            if node.right is None:
                node.right = TreeNode(val)
                return
            else:
                queue.append(node.right)

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

    def height_tree(self, tree, height=0):
        if tree is not None:
            if tree.left is not None or tree.right is not None:
                self.height_tree(tree.left, height + 1)
                self.height_tree(tree.right, height + 1)
            else:
                print(f'Height: {height}')


# class Solution:
    # def isBalanced(self, root: Optional[TreeNode]) -> bool:


def main():
    parser = argparse.ArgumentParser(prog='Balanced Binary Tree problem: https://leetcode.com/problems/balanced-binary-tree')
    parser.add_argument('--tree', type=str, required=True,
                        help='Input string to find is Binary Tree balanced or not (e.g. [3, 9, 20, None, None, 15, 7])')

    args = parser.parse_args()
    binary_tree = parse_binary_tree(args.tree)

    # Start root of binary tree
    root = TreeNode(binary_tree[0])

    # Fill binary tree with values from parser
    for i in range(1, len(binary_tree), 1):
        root.insert(binary_tree[i])

    root.print_tree()
    root.display_tree(root)
    root.height_tree(root)

    # res = isBalanced(root)

    # if(res):
    #     print('Height Balanced')
    # else:
    #     print('NOT Height Balanced')


if __name__ == "__main__":
    main()