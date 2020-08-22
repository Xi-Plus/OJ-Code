class Solution:
    def sumZero(self, n: int):
        return ([0] if n % 2 else []) + list(range(1, n // 2 + 1)) + list(range(-(n // 2), 0))


if __name__ == "__main__":
    print(Solution().sumZero(5))
    print(Solution().sumZero(3))
    print(Solution().sumZero(1))
