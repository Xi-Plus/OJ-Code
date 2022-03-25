class Solution:
    def twoCitySchedCost(self, costs):
        costs2 = [[i, j, j - i] for (i, j) in costs]
        costs2.sort(key=lambda v: v[2])
        ans = 0
        for i in range(len(costs2) // 2):
            ans += costs2[i][1]
        for i in range(len(costs2) // 2, len(costs2)):
            ans += costs2[i][0]
        return ans
