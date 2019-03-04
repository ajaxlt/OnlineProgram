#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 分数到小数(Fraction to Recurring Decimal)
 *
 * 描述:
 * 给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数
 * 如果小数部分为循环小数，则将循环的部分括在括号内
 *
 * 示例 1:
 * 输入: numerator = 1, denominator = 2
 * 输出: "0.5"
 *
 * 示例 2:
 * 输入: numerator = 2, denominator = 1
 * 输出: "2"
 *
 * 示例 3:
 * 输入: numerator = 2, denominator = 3
 * 输出: "0.(6)"
 *
 * 思路:
 * 1. 判断正负性
 * 2. 计算整数部分
 *
 * 3. 如果存在小数(除不尽)，进而计算小数部分
 *
 * 4. 用 map 记录算得的小数，如果已经存在，则说明到了循环节
 */
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        if (denominator == 0) return "NaN";
        long long num = numerator, den = denominator;
        string ans = num * den < 0 ? "-" : "";

        num = abs(num), den = abs(den);
        ans += to_string(num / den); // 整数部分

        num %= den; // 剩余未除尽的，用于算小数部分
        if (num != 0) ans += ".";
        else return ans;

        map<long long, int> m;
        string demicals = "";
        int i = 0;
        while(num != 0) {
            if (m.count(num)) {
                demicals.insert(m[num], "(");
                demicals += ")";
                return ans + demicals;
            }
            m[num] = i;
            demicals += to_string(num * 10 / den);
            num = num * 10 % den;
            ++i;
        }
        return ans + demicals;
    }
};