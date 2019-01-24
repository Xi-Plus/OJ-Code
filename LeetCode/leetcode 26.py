class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l = len(nums)
        i = 1
        while i < l:
            if nums[i] == nums[i-1]:
                nums.pop(i)
                l -= 1
            else:
                i += 1
        return l
