from collections import deque
import argparse
import re

TASK_NAME = 'Recover Binary Search Tree'
TASK_LINK = 'https://leetcode.com/problems/recover-binary-search-tree/'
TREE_ARG_HELP = 'Input string to check and fix Binary Search Tree (e.g. [1,3,None,None,2])'
COMPLEXITY_ARG_HELP = 'Choose complexity of the solution (linear or constant)'


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
    def recoverTree_linear_complexity(self, root):
        def inOrderTraversal(root, int_list) -> list:
            if root is None:
                return
            
            inOrderTraversal(root.left, int_list)
            int_list.append(root)
            inOrderTraversal(root.right, int_list)

        int_list = []
        inOrderTraversal(root, int_list)
        bad_nodes = []

        for i in range(1, len(int_list)):
            if int_list[i - 1].val > int_list[i].val:
                bad_nodes.append(int_list[i - 1])
                bad_nodes.append(int_list[i])

        bad_nodes[0].val, bad_nodes[-1].val = bad_nodes[-1].val, bad_nodes[0].val

    def recoverTree(self, root):
        def morrisTraversal_inorder(root):
            new_tree = []
            current = root

            while current is not None:
                if current.left is None:
                    print(f'Current left is None, append: {current.val}, new current: {current.right.val}')
                    new_tree.append(current)
                    current = current.right
                else:
                    print(f'Current left is not None, new previous: {current.left.val}')
                    previous = current.left
                    while previous.right is not None and previous.right != current:
                        print(f'Previous right is not None, new previous: {previous.right.val}')
                        previous = previous.right

                    if previous.right is None:
                        print(f'Previous.right is None, new previous.right: {current.val}, new current: {current.left.val}')
                        previous.right = current
                        current = current.left
                    else:
                        previous.right = None
                        print(f'Current right is not None, append: {current.val}')
                        new_tree.append(current)
                        current = current.right
            
            return new_tree

        new_tree = morrisTraversal_inorder(root)
        bad_nodes = []

        for i in range(1, len(new_tree)):
            if new_tree[i - 1].val > new_tree[i].val:
                bad_nodes.append(new_tree[i - 1])
                bad_nodes.append(new_tree[i])

        bad_nodes[0].val, bad_nodes[-1].val = bad_nodes[-1].val, bad_nodes[0].val


def main():
    parser = argparse.ArgumentParser(prog=f'{TASK_NAME}: {TASK_LINK}')
    parser.add_argument('--tree', type=str, required=True, help=f'{TREE_ARG_HELP}')
    parser.add_argument('--complexity', type=str, required=True, help=f'{COMPLEXITY_ARG_HELP}')

    args = parser.parse_args()
    binary_tree = parse_binary_tree(args.tree)

    root = TreeNode()
    root.insert(binary_tree)

    # Display the tree structure
    print("Tree structure:")
    root.display_tree(root)

    solution = Solution()

    if args.complexity == 'linear':
        solution.recoverTree_linear_complexity(root)

    if args.complexity == 'constant':
        solution.recoverTree(root)

    print('Tree after fix: ')
    root.display_tree(root)


if __name__ == "__main__":
    main()