#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: Excel表列序号(Excel Sheet Column Number)
 *
 * 描述:
 * 给定一个Excel表格中的列名称，返回其相应的列序号
 *
 * 思路:
 * 26进制转10进制
 */
class Solution {
public:
    long long titleToNumber(string s) {
        long long ans = 0;
        long long base = 1;
        for (int i = s.size() - 1; i >= 0; --i) {
            ans += (s[i] - 'A' + 1) * base;
            base *= 26;
        }
        return ans;
    }
};