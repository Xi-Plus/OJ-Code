class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        cnt = [0] * 26
        for c in s:
            cnt[ord(c) - 97] += 1
        for c in t:
            cnt[ord(c) - 97] -= 1
        for i in range(26):
            if cnt[i] != 0:
                return False
        return True
