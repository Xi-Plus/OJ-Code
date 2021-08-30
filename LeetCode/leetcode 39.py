import numpy as np


class Solution:
    def combinationSum(self, candidates, target):
        candidates.sort()
        cN = len(candidates)
        candidates.append(0)
        answer = []
        times = [0] * (cN + 1)
        while times[cN] == 0:
            t = np.dot(candidates, times)
            if t == target:
                temp = []
                for i in range(cN):
                    temp.extend([candidates[i]] * times[i])
                answer.append(temp)
                times[0] += 1
            elif t > target:
                times[0] = 0
                i = 1
                while i <= cN:
                    times[i] += 1
                    if np.dot(candidates, times) > target:
                        times[i] = 0
                        i += 1
                    else:
                        break
                if np.dot(candidates, times) > target:
                    break
            else:
                times[0] += 1
        return answer


if __name__ == "__main__":
    print(Solution().combinationSum([2, 3, 6, 7], 7))
    print(Solution().combinationSum([2, 3, 5], 8))
    print(Solution().combinationSum([2], 1))
    print(Solution().combinationSum([1], 1))
