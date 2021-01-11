import re


class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        return self.removeDuplicatesStack(s, k)

    def removeDuplicatesRe(self, s: str, k: int) -> str:
        c = 1
        while c > 0:
            s, c = re.subn(r'(.)\1{{{}}}'.format(k - 1), '', s)
        return s

    def removeDuplicatesStack(self, s: str, k: int) -> str:
        stack = ['*']
        count = [1]
        for i in range(len(s)):
            if s[i] == stack[-1]:
                if count[-1] + 1 == k:
                    for j in range(k - 1):
                        stack.pop()
                        count.pop()
                else:
                    stack.append(s[i])
                    count.append(count[-1] + 1)
            else:
                stack.append(s[i])
                count.append(1)
        return ''.join(stack)[1:]
