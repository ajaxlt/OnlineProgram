#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 两数相除(Implement strStr())
 *
 * 描述:
 * 给定两个整数，被除数 dividend 和除数 divisor
 * 将两数相除，要求不使用乘法、除法和 mod 运算符
 * 返回被除数 dividend 除以除数 divisor 得到的商
 *
 * 思路:
 * 根据题意，只能使用位运算， 因此需要用到 <<
 *
 * 我们可以将“商”用二进制表示
 * 并拆分成每位之和1, 2, 4, 8, 16 ...
 * 如果该位存在便加上
*/
class Solution {
public:
    int divide(long dividend, long divisor) {
        if (dividend == 0) return 0;
        else if (divisor == 1) return dividend;
        else if (divisor == -1) {
            if (dividend == INT32_MIN) return INT32_MAX;
            else return -dividend;
        }
        else {
            int res = 0;
            int sgn1 = 1, sgn2 = 1;
            if (dividend < 0) {
                sgn1 = -1;
                dividend = -dividend;
            }
            if (divisor < 0) {
                sgn2 = -1;
                divisor = -divisor;
            }

            // 基底法
            while (dividend >= divisor) {
                long cur = divisor, base = 1;
                while (dividend >= (cur << 1)) {
                    base = base << 1; // base = base * 2
                    cur = cur << 1;
                }
                dividend -= cur;
                res += base;
            }
            return sgn1 * sgn2 * res;
        }
    }
};