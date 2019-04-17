#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 最长有效括号(Longest Valid Parentheses)
 *
 * 描述:
 * 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度
 *
 * 示例 1:
 * 输入: "(()"
 * 输出: 2
 * 解释: 最长有效括号子串为 "()"
 *
 * 示例 2:
 * 输入: ")()())"
 * 输出: 4
 * 解释: 最长有效括号子串为 "()()"
 *
 * 思路:
 * 动态规划
 * 1. 建立一个长度为 len + 1 的数组dp, dp[i]表示以 i - 1 结尾的最长子串
 * 其中dp[0]表示什么都不取，初始化为0，边界条件
 * 2. 遍历 1 ~ len
 * 2.1 s[i - 1] = '('  ->  dp[i] = 0
 * 2.2 s[i - 1] = ')', 需要找到前 1 个待匹配的括号是不是'('
 * 其中 dp[i - 1] 的值表示了当前s[i - 1]的')'之前已经被匹配掉的括号数
 * 因此 j = i - 1 - dp[i - 1] - 1 便是那个待匹配的括号
 * 如果 s[j] = '(' 则匹配成功, 而且此时dp[j]也被连接上了
 * 因此 dp[i] = 2 + dp[i - 1] + dp[j]
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        int res = 0;
        vector<int> dp(len + 1, 0);
        for(int i = 1; i <= len; ++i) {
            if (s[i - 1] == '(') dp[i] = 0;
            else {
                int j = i - 1 - dp[i - 1] - 1;
                if (j >= 0 && s[j] == '(') {
                    dp[i] = 2 + dp[i - 1] + dp[j];
                    res = max(res, dp[i]);
                }
            }
        }
        return res;
    }
};