'''
5. 最长回文子串
'''
class Solution:
    def longestPalindrome(self, s: str) -> str:
        self.ans = ""
        def isPal(i, j):
            while i >= 0 and j < len(s) and s[i] == s[j]:
                i -= 1
                j += 1
                if len(self.ans) < j - i - 1:
                    self.ans = s[i + 1:j]
        for i in range(len(s)):
            isPal(i, i)
            isPal(i, i + 1)
        return self.ans

