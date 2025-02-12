
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:



def main():
    root = [3,9,20,None,None,15,7]
    res = isBalanced(root)

    if(res):
        print('Height Balanced')
    else:
        print('NOT Height Balanced')


if __name__ == "__main__":
    main()