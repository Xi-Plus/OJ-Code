class Solution:
    def maximumSwap(self, num):
        num = str(num)
        for i in range(len(num) - 1):
            maxd = 0
            maxp = -1
            for j in range(i + 1, len(num)):
                if int(num[j]) >= maxd:
                    maxp = j
                    maxd = int(num[j])
            if maxp != -1 and maxd > int(num[i]):
                return int(num[:i] + num[maxp] + num[i + 1:maxp] + num[i] + num[maxp + 1:])
        return int(num)


if __name__ == "__main__":
    print(Solution().maximumSwap(2736))
    print(Solution().maximumSwap(9973))
