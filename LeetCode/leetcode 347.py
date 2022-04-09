from collections import Counter


class Solution:
    def topKFrequent(self, nums, k):
        c = Counter(nums)
        return [p[0] for p in c.most_common(k)]
