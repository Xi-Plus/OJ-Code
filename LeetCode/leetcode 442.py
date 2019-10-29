class Solution:
    def findDuplicates(self, nums):
        dic = {}
        for v in nums:
            if v not in dic:
                dic[v] = 0
            dic[v] += 1
        ans = []
        for v in dic:
            if dic[v] >= 2:
                ans.append(v)
        return ans
