#include <iostream>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 数值的整数次方
 *
 * 描述: 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方
 *
 * 思路:
 * 1. 特殊输入的处理
 * 2. 分治
*/
const double eps = 1e-7;
class Solution {
public:
    double Power(double base, int exponent) {
        if (exponent == 0) return 1;
        else if (abs(base - 1) < eps) return 1;
        else if (exponent == 1) return base;
        else {
            if (exponent < 0) base = 1 / base, exponent = -exponent;
            double ans = Power(base, exponent / 2);
            if (exponent % 2 == 0) return ans * ans;
            else return ans * ans * base;
        }
    }
};