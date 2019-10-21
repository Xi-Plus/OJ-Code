from math import sqrt


class Solution:
    def arrangeCoins(self, n):
        return int((-1 + sqrt(1 + 8 * n)) / 2)
