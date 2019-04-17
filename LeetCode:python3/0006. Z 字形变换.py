'''
6. Z 字形变换
'''
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        tmp = [str() for i in range(numRows)]
        for i in range(len(s)):
            eff = i % (2 * numRows - 2)
            if eff < numRows:
                tmp[eff] += s[i]
            else:
                tmp[2 * numRows - eff - 2] += s[i]
        return "".join(tmp)

