class Solution:
    def firstMissingPositive(self, nums):
        dic = {}
        for v in nums:
            if v > 0:
                dic[v] = True
        ans = 1
        while True:
            if ans not in dic:
                return ans
            ans += 1
