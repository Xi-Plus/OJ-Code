import re


class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        c = 1
        while c > 0:
            s, c = re.subn(r'(.)\1{{{}}}'.format(k - 1), '', s)
        return s
