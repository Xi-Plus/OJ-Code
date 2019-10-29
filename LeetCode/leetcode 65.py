class Solution:
    def isNumber(self, s):
        try:
            float(s)
            return True
        except Exception:
            return False
