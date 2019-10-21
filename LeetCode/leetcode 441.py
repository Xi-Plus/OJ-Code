import math


class Solution:
    def arrangeCoins(self, n):
        return int((-1 + math.sqrt(1 + 8 * n)) / 2)
