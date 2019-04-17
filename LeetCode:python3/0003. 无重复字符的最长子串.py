'''
3. 无重复字符的最长子串

思路:
维护最长子串 curStr
检查当前遍历字符 c 否在 curStr 中出现
1. 若非, curStr后直接添加 c
2. 否则，找到 c 的下标位置, 舍去 c 以及 c 之前的串子
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

