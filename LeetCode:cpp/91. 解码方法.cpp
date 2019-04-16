#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 解码方法(Decode Ways)
 *
 * 描述:
 * 一条包含字母 A-Z 的消息通过以下方式进行了编码：
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 给定一个只包含数字的非空字符串，请计算解码方法的总数
 *
 * 示例 1:
 * 输入: "12"
 * 输出: 2
 * 解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
 *
 * 示例 2:
 * 输入: "226"
 * 输出: 3
 * 解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
 *
 * 思路:
 * 动态规划
 */


class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        int len = s.size();
        vector<int> dp(len + 1, 0);
        dp[0] = 1;
        if (s[0] != '0') dp[1] = 1;
        for (int i = 2; i < len + 1; ++i) {
            if (s[i - 1] != '0') dp[i] = dp[i - 1];
            if (s[i - 2] != '0' && s[i - 1] - '0' + 10 * (s[i - 2] - '0') <= 26) dp[i] += dp[i - 2];
            //cout << dp[i] << endl;
            if (dp[i] == 0) return 0;
        }
        return dp[len];
    }
};