'''
44. 通配符匹配

转移方程:
1. p[j - 1] = '*'
    1.1 该 * 匹配空串, 从 dp[i][j - 1] 转移
    1.2 该 * 匹配任意非空, 从 dp[i - 1][j] 转移
2. p[j - 1] != '*'
    从 dp[i - 1][j - 1] 转移
'''
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        dp = [[False for row in range(len(p) + 1)] for col in range(len(s) + 1)]
        dp[0][0] = True
        for i in range(1, len(s) + 1):
            dp[i][0] = False
        for j in range(1, len(p) + 1):
            dp[0][j] = True if (dp[0][j - 1] and p[j - 1] == '*') else False
        for i in range(1, len(s) + 1):
            for j in range(1, len(p) + 1):
                if p[j - 1] == '*':
                    dp[i][j] = True if (dp[i - 1][j] or dp[i][j - 1]) else False
                else:
                    dp[i][j] = True if (dp[i - 1][j - 1] and (s[i - 1] == p[j - 1] or p[j - 1] == '?')) else False

        return dp[len(s)][len(p)]

