class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        if dividend * divisor > 0:
            ans = abs(dividend) // abs(divisor)
        else:
            ans = abs(dividend) // abs(divisor) * -1
        ans = min(ans, 2147483647)
        return ans
