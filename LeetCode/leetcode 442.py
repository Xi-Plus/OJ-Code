class Solution:
    def findDuplicates(self, nums):
        temp = set()
        ans = set()
        for v in nums:
            if v not in temp:
                temp.add(v)
            else:
                ans.add(v)
        return ans
