#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 复原IP地址(Restore IP Addresses)
 *
 * 描述:
 * 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式
 *
 * 思路:
 * 回溯法
 */

class Solution {
public:
    void backtrack(string s, int i, string tmp) {
        if (i == 4) {
            if (s.empty()) {
                tmp.pop_back();
                ans.push_back(tmp);
            }
        }
        else {
            for (int j = 1; j <= 3 && j <= s.size(); ++j) {
                int remain = s.size() - j;
                if (remain > (4 - i - 1) * 3 || remain < (4 - i - 1) * 1) continue;
                if (j > 1 && s[0] == '0') break;
                string sub = s.substr(0, j);
                if (atoi(sub.c_str()) <= 255) backtrack(s.substr(j), i + 1, tmp + sub + '.');
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0, "");
        return ans;
    }
private:
    vector<string> ans;
};