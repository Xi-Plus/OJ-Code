import math


class Solution:
    def isGoodArray(self, nums):
        ans = nums[0]
        for v in nums:
            ans = math.gcd(ans, v)
            if ans == 1:
                return True
        return False
