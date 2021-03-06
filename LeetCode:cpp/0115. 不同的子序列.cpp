#include <iostream>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 不同的子序列(Distinct Subsequences)
 *
 * 描述:
 * 给定一个字符串 S 和一个字符串 T，计算在 S 的子序列中 T 出现的个数
 * 一个字符串的一个子序列是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串
 * （例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）
 *
 * 示例 1:
 * 输入: S = "rabbbit", T = "rabbit"
 * 输出: 3
 *
 * 解释:
 * 如下图所示, 有 3 种可以从 S 中得到 "rabbit" 的方案
 * (上箭头符号 ^ 表示选取的字母)
 *
 * rabbbit
 * ^^^^ ^^
 * rabbbit
 * ^^ ^^^^
 * rabbbit
 * ^^^ ^^^
 *
 * 示例 2:
 * 输入: S = "babgbag", T = "bag"
 * 输出: 5
 *
 * 解释:
 * 如下图所示, 有 5 种可以从 S 中得到 "bag" 的方案
 * (上箭头符号 ^ 表示选取的字母)
 *
 * babgbag
 * ^^ ^
 * babgbag
 * ^^    ^
 * babgbag
 * ^    ^^
 * babgbag
 * ^  ^^
 * babgbag
 * ^^^
 *
 * 思路:
 * 动态规划
 * s[i - 1] = t[j - 1]， dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1]
 * s[i - 1] != t[j - 1]，dp[i][j] = dp[i - 1][j]
 */

class Solution {
public:
    int numDistinct(string s, string t) {
        int len1 = s.size(), len2 = t.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        // dp[0][0] = 1
        // dp[0][j] = 0
        // dp[i][0] = 1
        for (int i = 0; i < len1 + 1; ++i) dp[i][0] = 1;
        for (int i = 1; i < len1 + 1; ++i) {
            for (int j = 1; j < len2 + 1; ++j) {
                // 如果, 两个尾相同:
                // 1. s 的尾不用 dp[i - 1][j]
                // 2. s 的尾用 dp[i - 1][j - 1]

                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[len1][len2];
    }
};