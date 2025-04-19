from collections import deque
from typing import Optional, List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def levelorder(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []
        if not root:
            return res
        
        q = deque()
        q.append(root)

        while q:
            level = []
            size = len(q)
            for _ in range(size):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
                level.append(node.val)
            res.append(level)
        
        return res

    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        level_traversal = self.levelorder(root)
        return [level[-1] for level in level_traversal]
