# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSymmetricUtil(self, root1: TreeNode, root2: TreeNode) -> bool:
        if root1 is None or root2 is None:
            return root1 == root2
        return (root1.val == root2.val and
                self.isSymmetricUtil(root1.left, root2.right) and
                self.isSymmetricUtil(root1.right, root2.left))

    def isSymmetric(self, root: TreeNode) -> bool:
        if root is None:
            return True
        return self.isSymmetricUtil(root.left, root.right)
