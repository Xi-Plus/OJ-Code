import heapq


class Solution:
    def halveArray(self, nums):
        cur_sum = sum(nums)
        half_sum = cur_sum / 2
        nums = list(map(lambda v: -v, nums))
        heapq.heapify(nums)
        cnt = 0
        while cur_sum > half_sum:
            max_v = -heapq.heappop(nums)
            max_v /= 2
            cur_sum -= max_v
            heapq.heappush(nums, -max_v)
            cnt += 1
        return cnt


if __name__ == '__main__':
    sol = Solution()
    print(sol.halveArray([5, 19, 8, 1]))
    print(sol.halveArray([3, 8, 20]))
