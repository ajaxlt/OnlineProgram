#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 通配符匹配(Wildcard Matching)
 *
 * 描述:
 * 给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
 *
 * '?' 可以匹配任何单个字符。
 * '*' 可以匹配任意字符串（包括空字符串）。
 * 两个字符串完全匹配才算匹配成功。
 *
 * 说明:
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。

 * 示例 1:
 * 输入:
 * s = "aa"
 * p = "a"
 * 输出: false
 * 解释: "a" 无法匹配 "aa" 整个字符串。
 *
 * 示例 2:
 * 输入:
 * s = "aa"
 * p = "*"
 * 输出: true
 * 解释: '*' 可以匹配任意字符串。
 *
 * 示例 3:
 * 输入:
 * s = "cb"
 * p = "?a"
 * 输出: false
 * 解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
 *
 * 示例 4:
 * 输入:
 * s = "adceb"
 * p = "*a*b"
 * 输出: true
 * 解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
 *
 * 示例 5:
 * 输入:
 * s = "acdcb"
 * p = "a*c?b"
 * 输入: false
 *
 *
 * 思路:
 * 动态规划
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        //1. 如果 p 是空的，则匹配与否取决于 s 是否空
        if(p.empty()) return s.empty();

        const int s_len = s.size(), p_len = p.size();
        bool dp[s_len + 1][p_len + 1];
        // dp[i][j] 表示 s[0~(i-1)] 与 s[0~(j-1)] 是否匹配
        dp[0][0] = true;

        for (int i = 0; i < s_len; ++i) dp[i + 1][0] = false;
        // 当 p 为空时， 定不能匹配
        for (int j = 0; j < p_len; ++j) dp[0][j + 1] = dp[0][j] && p[j] == '*';
        // 当 s 为空时， 当且仅当 p 全是 '*' 时匹配

        // dp[i + 1][j + 1] 是三种情况的并集
        // 1. dp[i][j] = true && s[i] 与 p[j] 匹配
        // 2. dp[i][j + 1] = true && p[j] = "*"
        // 3. dp[i + 1][j] = true && p[j] = "*"
        for (int i = 0; i < s_len; ++i) {
            for(int j = 0; j < p_len; ++j) {
                dp[i + 1][j + 1] = dp[i][j] && (s[i] == p[j] || p[j] == '?') || p[j] == '*' && (dp[i][j + 1] || dp[i + 1][j]);
            }
        }
        return dp[s_len][p_len];
    }
};