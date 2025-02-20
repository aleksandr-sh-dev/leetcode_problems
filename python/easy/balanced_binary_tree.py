from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = None
        self.right = None

    def insert(self, val):
        if self.val:
            if val < self.val:
                if self.left is None:
                    self.left = TreeNode(val)
                else:
                    self.left.insert(val)
            elif val > self.val:
                if self.right is None:
                    self.right = TreeNode(val)
                else:
                    self.right.insert(val)
        else:
            self.val = val

    def PrintTree(self):
        if self.left:
            self.left.PrintTree()
        print(self.val),
        if self.right:
            self.right.PrintTree()


# class Solution:
    # def isBalanced(self, root: Optional[TreeNode]) -> bool:


def main():
    root = TreeNode(3)
    root.insert(9)
    root.insert(20)
    root.insert(None)
    root.insert(None)
    root.insert(15)
    root.insert(7)
    root.PrintTree()
    # res = isBalanced(root)

    # if(res):
    #     print('Height Balanced')
    # else:
    #     print('NOT Height Balanced')


if __name__ == "__main__":
    main()