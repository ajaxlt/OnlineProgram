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
class Solution {
public:
    double Power(double base, int exponent) {
        //1. 若指数为0
        if (exponent == 0) {
            //1.1 0^0 无意义
            if (base == 0) throw ("Invalid Input");
            else return 1;
        }
        //2. 若指数为负， 则转换为正数
        if (exponent < 0) {
            exponent = -exponent;
            base = 1 / base;
        }
        //3. 设置边界，分治解之
        if (exponent == 1) return base;
        double binaryResult = Power(base, exponent / 2);
        if (exponent % 2 ==  0) return binaryResult * binaryResult;
        else return base * binaryResult * binaryResult;
    }
};