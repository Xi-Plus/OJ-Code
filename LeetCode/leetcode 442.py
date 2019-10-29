class Solution:
    def findDuplicates(self, nums):
        temp = set()
        ans = []
        for v in nums:
            if v not in temp:
                temp.add(v)
            else:
                ans.append(v)
        return ans
