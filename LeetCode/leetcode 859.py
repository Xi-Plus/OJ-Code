from collections import Counter
from collections import defaultdict


class Solution:
    def buddyStrings(self, A: str, B: str) -> bool:
        if len(A) != len(B):
            return False
        if A == B:
            return max(list(Counter(A).values()) + [0]) >= 2
        cntA = defaultdict(int)
        cntB = defaultdict(int)
        for i in range(len(A)):
            if A[i] != B[i]:
                cntA[A[i]] += 1
                cntB[B[i]] += 1
        return cntA == cntB and list(cntA.values()) == [1, 1]


if __name__ == "__main__":
    print(Solution().buddyStrings('ab', 'ba'))
    print(Solution().buddyStrings('ab', 'ab'))
    print(Solution().buddyStrings('aa', 'aa'))
    print(Solution().buddyStrings('aaaaaaabc', 'aaaaaaacb'))
    print(Solution().buddyStrings('', 'aa'))
