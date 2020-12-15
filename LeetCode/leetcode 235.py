# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        prefixp = self.find(root, p.val, '') + 'p'
        prefixq = self.find(root, q.val, '') + 'q'
        i = 0
        ans = root
        while prefixp[i] == prefixq[i]:
            if prefixp[i] == 'l':
                ans = ans.left
            else:
                ans = ans.right
            i += 1
        return ans

    def find(self, root, target, prefix):
        if root.val == target:
            return prefix
        temp = ''
        if root.left:
            temp += self.find(root.left, target, prefix + 'l')
        if root.right:
            temp += self.find(root.right, target, prefix + 'r')
        return temp
