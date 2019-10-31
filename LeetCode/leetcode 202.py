class Solution:
    def isHappy(self, n: int) -> bool:
        while n > 9:
            temp = 0
            while n > 0:
                temp += (n % 10)**2
                n //= 10
            n = temp
        return n in [1, 7]
