#include <iostream>
#include <string>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: Z 字形变换(Longest Palindromic Substring)
 *
 * 描述:
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列
 * 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
 *
 * 示例 1：
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 *
 * 示例 2：
 * 输入: "cbbd"
 * 输出: "bb"
 *
 *
 * 思路:
 * 中心扩展法
 * 1. 外层遍历整个字符串
 * 2. 针对与每个字符，以奇偶情况，分别进行中心扩展
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        const int len = 1000;
        vector<string> tmp(len, "");
        string rlt = "";
        for (int i = 0; i < s.length(); ++i) {
            int eff = i % (2 * numRows - 2); //等效变量
            if (eff < numRows) { //垂直项
                tmp[eff] += s[i];
            } else { //斜边项
                tmp[2 * numRows - eff - 2] += s[i];
            }
        }
        for (int i = 0; i < numRows; ++i) rlt += tmp[i];
        return rlt;
    }
};