class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        dic = {
            ")": "(",
            "]": "[",
            "}": "{"
        }
        stack = []
        for c in s:
            if c in ")]}":
                if len(stack) == 0:
                    return False
                if dic[c] != stack[-1]:
                    return False
                stack.pop()
            else:
                stack.append(c)
        if len(stack) != 0:
            return False
        return True
