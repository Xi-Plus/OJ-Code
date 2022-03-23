class Solution:
    def maxSubArray(self, nums):
        return self._ans1(nums)

    def _ans1(self, nums):
        ans = -1e7
        cur = 0
        for n in nums:
            cur += n
            ans = max(ans, cur)
            cur = max(cur, 0)
        return ans

    def _ans2(self, nums):
        return self._solve(nums)

    def _solve(self, nums):
        if len(nums) == 1:
            return nums[0]
        mid = len(nums) // 2

        lmax = nums[mid - 1]
        temp = 0
        for n in nums[mid - 1::-1]:
            temp += n
            lmax = max(lmax, temp)

        rmax = nums[mid]
        temp = 0
        for n in nums[mid:]:
            temp += n
            rmax = max(rmax, temp)

        return max([
            self._solve(nums[:mid]),
            self._solve(nums[mid:]),
            lmax + rmax
        ])


if __name__ == '__main__':
    sol = Solution()
    print(sol.maxSubArray([-2, 1, -3, 4, -1, 2, 1, -5, 4]))
    print(sol.maxSubArray([1]))
    print(sol.maxSubArray([5, 4, -1, 7, 8]))
    print(sol.maxSubArray([-1]))
