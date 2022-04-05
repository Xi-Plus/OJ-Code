class Solution:
    def nextPermutation(self, nums):
        i = len(nums) - 1
        while i > 0 and nums[i - 1] >= nums[i]:
            i -= 1
        if i == 0:
            nums.reverse()
            return
        j = i
        while j < len(nums) - 1 and nums[j + 1] > nums[i - 1]:
            j += 1
        nums[i - 1], nums[j] = nums[j], nums[i - 1]
        nums[i:] = reversed(nums[i:])


if __name__ == '__main__':
    sol = Solution()
    nums = [1, 2, 3, 4]
    sol.nextPermutation(nums)
    print(nums)
    nums = [1, 4, 3, 2]
    sol.nextPermutation(nums)
    print(nums)
    nums = [4, 3, 2, 1]
    sol.nextPermutation(nums)
    print(nums)
    nums = [5, 1, 1]
    sol.nextPermutation(nums)
    print(nums)
