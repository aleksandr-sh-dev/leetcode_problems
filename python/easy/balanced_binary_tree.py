from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = None
        self.right = None

    def insert(self, val):
        if self.val:
            if self.left is None:
                print(f'Left tree: {val}')
                self.left = TreeNode(val)
            elif self.right is None:
                print(f'Right tree: {val}')
                self.right = TreeNode(val)
            else:
                if self.left.left is None or self.left.right is None:
                    print(f'Next left tree')
                    self.left.insert(val)
                else:
                    print('Next right tree')
                    self.right.insert(val)
        else:
            self.val = val

    def PrintTree(self):
        if self.left:
            self.left.PrintTree()
        print(self.val),
        if self.right:
            self.right.PrintTree()

    def display_tree(self, tree, level=0, prefix="Root: "):
        """(Made with DeepSeek) Recursively display the binary tree."""
        if tree is not None:
            print(" " * (level * 4) + prefix + str(tree.val))
            if tree.left is not None or tree.right is not None:
                self.display_tree(tree.left, level + 1, "L--- ")
                self.display_tree(tree.right, level + 1, "R--- ")


# class Solution:
    # def isBalanced(self, root: Optional[TreeNode]) -> bool:


def main():
    root = TreeNode(3)
    print(f'Init TreeNode root with value: {root.val}')
    root.insert(9)
    root.insert(20)
    root.insert(None)
    root.insert(None)
    root.insert(15)
    root.insert(7)
    root.PrintTree()
    root.display_tree(root)
    # res = isBalanced(root)

    # if(res):
    #     print('Height Balanced')
    # else:
    #     print('NOT Height Balanced')


if __name__ == "__main__":
    main()