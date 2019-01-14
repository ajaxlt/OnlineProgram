#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 交错字符串(Interleaving String)
 *
 * 描述:
 * 给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。
 *
 * 示例 1:
 * 输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * 输出: true
 *
 * 示例 2:
 * 输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 *   输出: false
 *
 * 思路:
 * 首先，用递归会超时
 * 因此，尝试用动态规划
 * 定义 dp[i][j] 表示 s1[0..i-1] 与 s2[0..j-1] 是否能组成交错字符串 s3[0..i+j-1]
 * 1. dp[0][0] 置 true, 因为 s1, s2, s3 均为空时，是交错字符串
 * 2. 如果单取s1或者单取s2，当且仅当字符串相同时为true，即
 *  2.1 dp[i][0] = true, if dp[i - 1][0] = true and s1[i - 1] = s3[i - 1]
 *  2.2 dp[0][j] = true, if dp[0][j - 1] = true and s2[j - 1] = s3[j - 1]
 * 3. 如果 dp[i - 1][j] = true, dp[i][j] 含义为 s1 多取一个
 * 那么 dp[i][j] = true, if s1[i - 1] = s3 [i + j - 1]
 * 因此，可以总结
 * dp[i][j] = true, if dp[i - 1][j] = true and s1[i - 1] = s3[i + j - 1]
 *                  or dp[i][j - 1] = true and s2[j - 1] = s3[i + j - 1]
 *
 */

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
        if (len1 + len2 != len3) return false;

        vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
        dp[0][0] = true;

        for(int i = 1; i <= len1; ++i) {
            if (s1[i - 1] == s3[i - 1]) dp[i][0] = true;
            else break;
        }
        for (int j = 1; j <= len2; ++j) {
            if (s2[j - 1] == s3[j - 1]) dp[0][j] = true;
            else break;
        }

        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1] ||
                    dp[i][j - 1] && s2[j - 1] == s3[i + j - 1])
                    dp[i][j] = true;
            }
        }
        return dp[len1][len2];
    }
};