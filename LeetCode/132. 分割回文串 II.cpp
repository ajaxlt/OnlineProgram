#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 分割回文串II(Palindrome Partitioning II )
 *
 * 描述:
 * 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串
 * 返回符合要求的最少分割次数
 *
 * 示例:
 * 输入: "aab"
 * 输出: 1
 * 解释: 进行一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。

 * 思路:
 * 动态规划
 */

class Solution {
public:
    bool isPal(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j)
            if (s[i++] != s[j--]) return false;
        return true;
    }
    int minCut(string s) {
        int len = s.size();
        if (len == 0) return -1;
        vector<int> dp(len + 1, 0);
        //dp[i] 表示 以 s[0 ~ i - 1] 的最小分割

        // 1. 如果 s[0 ~ i - 1] 是回文, 则dp[i] = 0
        // 2. 否则, dp[i] 初始化为 i - 1 (上界)
        //    遍历 1 ~ i - 1
        // 2.1 如果 j ~ i - 1 是回文, dp[i] = min(dp[i], dp[j] + 1)
        // 2.2 否则, dp[i] = min(dp[i], dp[j] + i - j)
        for (int i = 1; i <= len; ++i) {
            if (isPal(s.substr(0, i))) {
                dp[i] = 0;
                continue;
            }
            else dp[i] = i - 1;
            for (int j = 1; j < i; ++j) {
                if (isPal(s.substr(j, i - j))) dp[i] = min(dp[i], dp[j] + 1);
                else dp[i] = min(dp[i], dp[j] + i - j);
            }
        }
        return dp[len];
    }
};