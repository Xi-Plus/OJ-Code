class Solution:
    def findDuplicates(self, nums):
        dic = {}
        ans = set()
        for v in nums:
            if v not in dic:
                dic[v] = 0
            else:
                ans.add(v)
        return ans
