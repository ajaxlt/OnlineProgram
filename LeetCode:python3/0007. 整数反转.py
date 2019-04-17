'''
7. 整数反转
'''
class Solution:
    def reverse(self, x: int) -> int:
        sgn = 1 if x > 0 else -1
        ans = sgn * int(str(abs(x))[::-1])
        return ans if -2**31 < ans < 2**31 - 1 else 0

