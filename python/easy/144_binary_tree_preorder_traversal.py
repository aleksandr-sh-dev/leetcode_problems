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
        self.left = left
        self.right = right

    def insert(self, values):
        """Constructs a binary tree from a list of values, including None."""
        if not values:
            return None

        # Create the root node
        self.val = values[0]
        queue = deque([self])
        idx = 1

        while queue and idx < len(values):
            node = queue.popleft()

            # Assign left child
            if idx < len(values) and values[idx] is not None:
                node.left = TreeNode(values[idx])
                queue.append(node.left)
            idx += 1

            # Assign right child
            if idx < len(values) and values[idx] is not None:
                node.right = TreeNode(values[idx])
                queue.append(node.right)
            idx += 1

    def display_tree(self, tree, level=0, prefix="Root: "):
        """Recursively display the binary tree."""
        if tree is not None:
            print(" " * (level * 4) + prefix + str(tree.val))
            if tree.left is not None or tree.right is not None:
                self.display_tree(tree.left, level + 1, "L--- ")
                self.display_tree(tree.right, level + 1, "R--- ")
                
    def height_tree(self, tree) -> int:
        if tree is None:
            return -1
        
        return 1 + max(self.height_tree(tree.left), self.height_tree(tree.right))
    
class Solution:
    def preorderTraversal(self, root) -> list:
        def traversal(root, int_list):
            if root is not None:
                int_list.append(root.val)
                traversal(root.left, int_list)
                traversal(root.right, int_list)
                    
        int_list = []
        traversal(root, int_list)

        return int_list


def main():
    parser = argparse.ArgumentParser(prog='Binary Tree Preorder Traversal: https://leetcode.com/problems/binary-tree-preorder-traversal')
    parser.add_argument('--tree', type=str, required=True,
                        help='Input string to Preorder Traversal Binary Tree (e.g. [3,9,20,None,None,15,7])')

    args = parser.parse_args()
    binary_tree = parse_binary_tree(args.tree)

    root = TreeNode()
    root.insert(binary_tree)

    # Display the tree structure
    print("Tree structure:")
    root.display_tree(root)

    # Perform preorder traversal
    solution = Solution()
    output_list = solution.preorderTraversal(root)
    print(f'Output: {output_list}')


if __name__ == "__main__":
    main()