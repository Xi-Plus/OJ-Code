# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def isValidBST(self, root):
        return self._check(root, float('-inf'), float('inf'))

    def _check(self, root, l, r):
        if root is None:
            return True
        if not l < root.val < r:
            return False
        return self._check(root.left, l, root.val) and self._check(root.right, root.val, r)
