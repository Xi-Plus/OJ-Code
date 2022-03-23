class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans = -1e7
        cur = 0
        for n in nums:
            cur += n
            ans = max(ans, cur)
            cur = max(cur, 0)
        return ans
