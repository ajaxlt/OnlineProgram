#include <iostream>
#include <string>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 最长不含重复字符的子字符串
 *
 * 描述:
 * 从字符串中找出一个最长不含有重复字符的子字符串，输出其长度
 *
 * 思路:
 * 限尾dp法,
 * dp[i] = dp[i - 1] + 1 -> if str[i] not exist before or ... str[i] exist, and distance of duplication over length
 * dp[i] = i - exits[i] -> else
*/

class Solution {
public:
    int longestSubstringWithoutDuplication(string str) {
        size_t len = str.length();
        int exist['z' - 'a'], dp[len];
        int maxLen = 0;
        for (int i = 0; i < 'z' - 'a'; ++i) exist[i] = -1; // 表示没有用到
        dp[0] = 1, exist['z' - str[0]] = 0;
        for (int i = 1; i < len; ++i) {
            if (exist['z' - str[i]] == -1 || i - exist['z' - str[i]] > dp[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
            else {
                dp[i] = i - exist['z' - str[i]];
            }
            exist['z' - str[i]] = i;
            maxLen = max(maxLen, dp[i]);
            cout << dp[i] << endl;
        }
        return maxLen;
    }
};

int main() {
    Solution s;
    cout << s.longestSubstringWithoutDuplication("arabcacfr") << endl;
}