class Solution:
    def missingNumber(self, nums):
        n = nums[0]
        findzero = False
        total = 0
        for v in nums:
            n = max(n, v)
            total += v
            if v == 0:
                findzero = True
        total2 = n * (n + 1) // 2
        if not findzero:
            return 0
        if total2 == total:
            return n + 1
        return total2 - total
