#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: Z 字形变换(ZigZag Conversion)
 *
 * 描述:
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列
 * 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
 * L   C   I   R
 * E T O E S I I G
 * E   D   H   N
 *
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串
 * 即 "LCIRETOESIIGEDHN"
 *
 *
 * 思路:
 * 数学题，找规律
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