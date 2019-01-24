class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        s += " "
        i = 0
        ans = 0
        while i < len(s) - 1:
            if s[i] == "I":
                if s[i+1] == "V":
                    ans += 4
                    i += 1
                elif s[i+1] == "X":
                    ans += 9
                    i += 1
                else:
                    ans += 1
            elif s[i] == "X":
                if s[i+1] == "L":
                    ans += 40
                    i += 1
                elif s[i+1] == "C":
                    ans += 90
                    i += 1
                else:
                    ans += 10
            elif s[i] == "C":
                if s[i+1] == "D":
                    ans += 400
                    i += 1
                elif s[i+1] == "M":
                    ans += 900
                    i += 1
                else:
                    ans += 100
            elif s[i] == "V":
                ans += 5
            elif s[i] == "L":
                ans += 50
            elif s[i] == "D":
                ans += 500
            elif s[i] == "M":
                ans += 1000
            i += 1
        return ans
