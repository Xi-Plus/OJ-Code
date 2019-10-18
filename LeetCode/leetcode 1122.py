class Solution:
    def relativeSortArray(self, arr1, arr2):
        cnt = {}
        other = []
        for key in arr2:
            cnt[key] = 0
        for val in arr1:
            if val in cnt:
                cnt[val] += 1
            else:
                other.append(val)
        ans = []
        for key in arr2:
            for i in range(cnt[key]):
                ans.append(key)
        other.sort()
        ans.extend(other)
        return ans
