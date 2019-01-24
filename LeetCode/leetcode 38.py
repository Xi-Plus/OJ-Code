# https://leetcode.com/problems/count-and-say/

class Solution:
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        s = "1"
        for i in range(n-1):
            s2 = ""
            s += "-"
            last = s[0]
            lastn = 1
            for c in s[1:]:
                if c != last:
                    s2 += str(lastn) + last
                    last = c
                    lastn = 1
                else:
                    lastn += 1
            s = s2
        return s
