#include <iostream>
#include <string.h>
#include <string>
#include <stack>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 把字符串转换成整数
 *
 * 描述:
 * 输入一个字符串,包括数字字母符号,可以为空
 * 如果是合法的数值表达则返回该数字，否则返回0
 *
 * 思路:
 * 简单题
 *
*/
class Solution {
public:
    inline bool isLegal(char c) {
        return c <= '9' && c >= '0';
    }
    int StrToInt(string str) {
        if (str.empty()) return 0;
        int sign = 1, i = 0, rlt = 0;
        if (str[i] == '+') {
            ++i;
        } else if (str[i] == '-') {
            sign = -1;
            ++i;
        } else if (!isLegal(str[i])) return 0;
        for (; i < str.length(); ++i) {
            if(!isLegal(str[i])) return 0;
            rlt = rlt * 10 + str[i] - '0';
        }
        return sign * rlt;
    }
};
int main() {
    Solution s;
    cout << s.StrToInt("123") << endl;
}