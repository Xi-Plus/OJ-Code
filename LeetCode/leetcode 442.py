class Solution:
    def findDuplicates(self, nums):
        dic = {}
        ans = []
        for v in nums:
            if v not in dic:
                dic[v] = 0
            dic[v] += 1
            if dic[v] == 2:
                ans.append(v)
        return ans
