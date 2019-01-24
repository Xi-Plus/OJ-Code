class Solution:
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        n = int("".join(map(str, digits)))
        n += 1
        l = [int(c) for c in str(n)]
        return l
