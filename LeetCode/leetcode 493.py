from bisect import bisect_left


class Solution:
    N = 0
    BIT = []

    def _add(self, idx, v):
        while idx > 0:
            self.BIT[idx] += v
            idx -= idx & (-idx)

    def _get(self, idx):
        ans = 0
        while idx <= self.N:
            ans += self.BIT[idx]
            idx += idx & (-idx)
        return ans

    def reversePairs(self, nums):
        self.N = len(nums)
        sorted_nums = sorted(nums[:])
        self.BIT = [0] * (self.N + 1)
        ans = 0
        for i in range(self.N):
            ans += self._get(bisect_left(sorted_nums, nums[i] * 2 + 1) + 1)
            self._add(bisect_left(sorted_nums, nums[i]) + 1, 1)
        return ans
