class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        s = str(x)
        n = ""
        if s[0] == "-":
            n = "-"
            s = s[1:]
        ans = int(n + s[::-1])
        if ans < -2**31 or ans > 2**31 - 1:
            return 0
        return ans
