class Solution:
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        s = s.strip()
        if len(s) == 0:
            return 0
        last = s.split(" ")[-1]
        cnt = 0
        for c in last:
            if c >= 'a' and c <= 'z' or c >= 'A' and c <= 'Z':
                cnt += 1
        return cnt
