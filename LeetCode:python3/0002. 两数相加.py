'''
3. 两数相加
'''
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = 0
        curStr = ""
        for c in s:
            if c not in curStr:
                curStr += c
            else:
                curStr = curStr[curStr.index(c) + 1:] + c
            ans = max(ans, len(curStr))
        return ans
