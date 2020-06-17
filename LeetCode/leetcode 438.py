class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if len(s) < len(p):
            return []
        cnt = [0] * 26
        notzero = 0
        for c in p:
            n = ord(c) - 97
            cnt[n] -= 1
            if cnt[n] == -1:
                notzero += 1
        plen = len(p)
        ans = []
        for i in range(plen):
            n = ord(s[i]) - 97
            cnt[n] += 1
            if cnt[n] == 0:
                notzero -= 1
                if notzero == 0:
                    ans.append(i - len(p) + 1)
        for i in range(plen, len(s)):
            n = ord(s[i]) - 97
            cnt[n] += 1
            if cnt[n] == 0:
                notzero -= 1
            n = ord(s[i - plen]) - 97
            cnt[n] -= 1
            if cnt[n] == -1:
                notzero += 1
            if notzero == 0:
                ans.append(i - len(p) + 1)
        return ans
