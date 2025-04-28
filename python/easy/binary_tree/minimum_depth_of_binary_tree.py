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

def get_minimum(list) -> int:
    if list:
        return min(list)
    else:
        return float('inf')

min_depth_list_glob = []
class Solution:
    # O(n) complexity    
    def minDepth_linear_complexity(self, root) -> int:
        def traversal(root, depth_list, depth):
            if root is not None:
                depth += 1
                minimum = get_minimum(min_depth_list_glob)
                if depth >= minimum:
                    return
                if root.left is None and root.right is None:
                    print(f'Enter height: {depth}')
                    depth_list.append(depth)
                traversal(root.left, depth_list, depth)
                traversal(root.right, depth_list, depth)

        if root is None:   
            return 0
        
        depth = 0
        traversal(root, min_depth_list_glob, depth)

        minimum = get_minimum(min_depth_list_glob)
        min_depth_list_glob.clear()
        return minimum


def main():
    parser = argparse.ArgumentParser(prog='Minimum Depth of Binary Tree: https://leetcode.com/problems/minimum-depth-of-binary-tree')
    parser.add_argument('--tree', type=str, required=True,
                        help='Input string to get minimal depth of Binary Tree (e.g. [3,9,20,None,None,15,7])')

    args = parser.parse_args()
    binary_tree = parse_binary_tree(args.tree)

    root = TreeNode()
    root.insert(binary_tree)

    # Display the tree structure
    print("Tree structure:")
    root.display_tree(root)

    # Perform preorder traversal
    solution = Solution()
    min_height_lin = solution.minDepth_linear_complexity(root)
    # min_height = solution.minDepth(root)
    print(f'Minimal height of binary tree: \nlinear: {min_height_lin}\n(write better): ')


if __name__ == "__main__":
    main()