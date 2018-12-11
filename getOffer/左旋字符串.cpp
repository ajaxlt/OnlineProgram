#include <iostream>
#include <string.h>
#include <string>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 左旋转字符串
 *
 * 描述:
 * 对于一个给定的字符序列S，请你把其循环左移K位后的序列输出
 * 例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”
 *
 * 思路:
 * 简单题
 *
*/
class Solution {
public:
    string LeftRotateString(string str, int n) {
        //if (n < 0) throw('Invalid Input');
        if (n == 0 || str.empty()) return str;
        const int len = str.length();
        n = n % len;
        string rlt = string(len, ' ');
        for (int i = 0; i < len; ++i) {
            if (i < len - n) rlt[i] = str[i + n];
            else rlt[i] = str[i + n - len];
        }
        return rlt;
    }
};