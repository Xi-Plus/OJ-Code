class Solution:
    def balancedStringSplit(self, s: str) -> int:
        ans = 0
        cnt = 0
        for c in s:
            if c == 'R':
                cnt += 1
            else:
                cnt -= 1
            if cnt == 0:
                ans += 1
        return ans
