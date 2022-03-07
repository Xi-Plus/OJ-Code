class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        ans = [[0 for i in range(query_row + 1)] for j in range(query_row + 1)]
        ans[0][0] += poured
        for i in range(0, query_row):
            for j in range(i + 1):
                if ans[i][j] > 1:
                    out = (ans[i][j] - 1) / 2
                    ans[i + 1][j] += out
                    ans[i + 1][j + 1] += out
        return min(ans[query_row][query_glass], 1)
