import re


class Solution:
    def isMatch(self, s, p):
        if re.search('^' + p + '$', s):
            return True
        return False


if __name__ == "__main__":
    print(Solution().isMatch('aa', 'a'))
    print(Solution().isMatch('aa', 'a*'))
    print(Solution().isMatch('ab', '.*'))
    print(Solution().isMatch('aab', 'c*a*b*'))
    print(Solution().isMatch('mississippi', 'mis*is*p*.'))
