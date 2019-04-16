#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 字符串相乘(Multiply Strings)
 *
 * 描述:
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式
 *
 *
 * 思路:
 * 设num1的长度为 n，num2的长度为 m， 则product的长度至多为 n + m (n + m 或 n + m - 1)
 * 我们可以按位将 num1，num2上特定两位的相乘放到特定的位置，先不进位，最后再总体进位
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        if (num1 == "1") return num2;
        if (num2 == "1") return num1;

        const int len1 = num1.size(), len2 = num2.size(), len = len1 + len2;
        int res[len];
        memset(res, 0, sizeof(res));
        for (int i = len1 - 1; i >= 0; --i) {
            for (int j = len2 - 1; j >= 0; --j) {
                res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        int carry = 0;
        string product = "";
        for (int i = len - 1; i > 0; --i){
            res[i] += carry;
            if (res[i] >= 10) {
                carry = res[i] / 10;
                res[i] = res[i] % 10;
            } else carry = 0;
            product = to_string(res[i]) + product;
        }
        if (res[0] + carry != 0) product = to_string(res[0] + carry) + product;
        return product;
    }
};