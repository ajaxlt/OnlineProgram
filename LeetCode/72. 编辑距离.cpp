#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 编辑距离(Edit Distance)
 *
 * 描述:
 * 给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数
 * 你可以对一个单词进行如下三种操作：
 *
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 *
 * 示例 1:
 * 输入: word1 = "horse", word2 = "ros"
 * 输出: 3
 * 解释:
 * horse -> rorse (将 'h' 替换为 'r')
 * rorse -> rose (删除 'r')
 * rose -> ros (删除 'e')
 *
 * 示例 2:
 * 输入: word1 = "intention", word2 = "execution"
 * 输出: 5
 * 解释:
 * intention -> inention (删除 't')
 * inention -> enention (将 'i' 替换为 'e')
 * enention -> exention (将 'n' 替换为 'x')
 * exention -> exection (将 'n' 替换为 'c')
 * exection -> execution (插入 'u')
 *
 * 思路:
 * dp[i][j]: s 的前i 个字符和 t 的前 j 个字符的最少操作数(s[i - 1], t[j - 1])
 *
 * dp[0][0] = 0
 * dp[i][0] = i
 * dp[0][j] = j
 *
 *
 * 1. dp[i][j - 1] + 1;
 * 2. dp[i - 1][j] + 1;
 * 3. s[i - 1] = t[j - 1] -> dp[i - 1][j - 1]
 *    else dp[i - 1][j - 1]
 *
 * dp[i][j] = min ...
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        if (len1 == 0 || len2 == 0) return len1 + len2;

        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 1; i <= len1; ++i) dp[i][0] = i;
        for (int j = 1; j <= len2; ++j) dp[0][j] = j;

        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                int tar1 = 1 + min(dp[i][j - 1], dp[i - 1][j]);
                int tar2 = word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1] : dp[i - 1][j - 1] + 1;
                dp[i][j] = min(tar1, tar2);
            }
        }
        return dp[len1][len2];
    }
};