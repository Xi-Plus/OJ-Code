import numpy as np
import scipy.signal


class Solution:
    def gameOfLife(self, board):
        """
        Do not return anything, modify board in-place instead.
        """
        feature = np.array([
            [2, 2, 2],
            [2, 1, 2],
            [2, 2, 2],
        ])
        temp = scipy.signal.convolve2d(board, feature, mode='same')
        temp = -(temp - 6)**2 + 2
        temp = (1 / (1 + np.exp(-temp)))
        temp = np.rint(temp).astype(int)

        for i in range(len(board)):
            for j in range(len(board[0])):
                board[i][j] = temp[i][j]


if __name__ == '__main__':
    sol = Solution()
    board = [[0, 1, 0], [0, 0, 1], [1, 1, 1], [0, 0, 0]]
    sol.gameOfLife(board)
    print(board)
    board = [[1, 1], [1, 0]]
    sol.gameOfLife(board)
    print(board)
