class Solution:
    def findMin(self, nums):
        if len(nums) == 1:
            return nums[0]
        if nums[0] < nums[-1]:
            return nums[0]
        l = 0
        r = len(nums) - 1
        m = (l + r) // 2
        while l < r:
            m = (l + r) // 2
            if nums[m] > nums[l]:
                l = m
            else:
                r = m
        return nums[m + 1]
