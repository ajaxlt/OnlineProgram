#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 整数反转(Reverse Integer)
 *
 * 描述:
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转
 *
 * 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]
 * 请根据这个假设，如果反转后整数溢出那么就返回 0
 *
 * 思路:
 * 简单题
*/

class Solution {
public:
    int reverse(int x) {
        int flag = 1;
        if (x < 0) {
            flag = -1;
            x = -x;
        }
        long rlt = 0;
        while (x) {
            rlt = rlt * 10 + x % 10;
            x /= 10;
        }
        rlt = rlt * flag;
        if (rlt >= INT32_MAX || rlt <= INT32_MIN) return 0;
        else return rlt;
    }
};