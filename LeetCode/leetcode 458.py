import math


class Solution:
    def poorPigs(self, buckets, minutesToDie, minutesToTest):
        T = int(minutesToTest / minutesToDie)
        return math.ceil(math.log(buckets) / math.log(T + 1))


if __name__ == "__main__":
    print(Solution().poorPigs(1000, 15, 60))
    print(Solution().poorPigs(4, 15, 15))
