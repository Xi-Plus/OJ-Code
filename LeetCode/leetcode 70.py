class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        l = [1, 1, 2]
        for i in range(2, n):
            l.append(l[-1] + l[-2])
        return l[n]
