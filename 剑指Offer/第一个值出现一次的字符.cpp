#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 第一个只出现一次的字符
 *
 * 描述:
 * 在字符串中找到第一个只出现一次的字符，返回其下标，若无则返回-1
 *
 * 思路:
 * 打表
*/

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if (str.empty()) return -1;
        const int len = 'z' - 'A' + 1;
        int m[len];
        for (int i = 0; i < len; ++i)
            m[i] = -2;
        for (int i = 0; i < str.length(); ++i) {
            if (m[str[i] - 'A'] == -2) m[str[i] - 'A'] = i;
            else m[str[i]- 'A'] = str.length();
        }
        int Min = str.length();
        for (int i = 0; i < len; ++i) {
            if (m[i] != -2) Min = min(Min, m[i]);
        }
        return Min == str.length() ? -1 : Min;
    }
};

int main() {
    Solution s;
    cout << s.FirstNotRepeatingChar("kYVmIJVzYWPQLtIdKMmvkVSoKtqJANOfCCOfLVJEjjhbnPrDOwKCDeqhts");
}