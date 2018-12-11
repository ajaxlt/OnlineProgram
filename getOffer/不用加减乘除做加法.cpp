#include <iostream>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 不用加减乘除做加法
 *
 * 描述:
 * 写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号
 *
 * 思路:
 * 根据十进制加法的一般方法
 * 1. 各位相加(取低位), 例如 19 + 21, (1 + 2) % 10 = 3; (9 + 1) % 10 = 0 -> 30
 * 2. 各位相加(取高位) * Base, 例如 (1 + 2) / 10 = 0; (9 + 1) / 10 = 1 -> (01) * 10 = 10
 * 3. 1. + 2. 即是答案
 *
 * 二进制同样适用
 * 1. a ^ b
 * 2. (a & b) << 1
 * 3. 迭代，直到 2. 为0， 1. 便是所求
 *
*/
class Solution {
public:
    int Add(int num1, int num2)
    {
        while(num2) {
            int rlt1 = num1 ^ num2;
            int rlt2 = (num1 & num2) << 1;
            num1 = rlt1, num2 = rlt2;
        }
        return num1;
    }
};