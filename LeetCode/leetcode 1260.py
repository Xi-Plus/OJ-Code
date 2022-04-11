import numpy as np


class Solution:
    def shiftGrid(self, grid, k):
        grid = np.array(grid)
        grid = np.roll(grid, k)
        return grid.tolist()


if __name__ == '__main__':
    sol = Solution()
    print(sol.shiftGrid([[1, 2, 3], [4, 5, 6], [7, 8, 9]], 1))
    print(sol.shiftGrid([[3, 8, 1, 9], [19, 7, 2, 5], [4, 6, 11, 10], [12, 0, 21, 13]], 4))
