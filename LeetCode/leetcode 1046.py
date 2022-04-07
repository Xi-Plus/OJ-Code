import heapq


class Solution:
    def lastStoneWeight(self, stones) -> int:
        stones = list(map(lambda v: -v, stones))
        heapq.heapify(stones)
        while len(stones) >= 2:
            a = -heapq.heappop(stones)
            b = -heapq.heappop(stones)
            print(a, b)
            if a != b:
                heapq.heappush(stones, -abs(a - b))
        if len(stones) > 0:
            return -stones[0]
        return 0
