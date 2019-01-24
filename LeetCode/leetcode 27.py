class Solution:
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        l = len(nums)
        i = 0
        while i < l:
            if nums[i] == val:
                nums.pop(i)
                l -= 1
            else:
                i += 1
