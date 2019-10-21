class Solution:
    def thirdMax(self, nums):
        MIN = -100000000000
        ans = [MIN, MIN, MIN]
        for v in nums:
            if v in ans:
                continue
            if v > ans[0]:
                ans[2] = ans[1]
                ans[1] = ans[0]
                ans[0] = v
            elif v > ans[1]:
                ans[2] = ans[1]
                ans[1] = v
            elif v > ans[2]:
                ans[2] = v
        if ans[2] != MIN:
            return ans[2]
        else:
            return ans[0]
