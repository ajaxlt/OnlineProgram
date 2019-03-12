#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 位1的个数(Number of 1 Bits)
 *
 * 描述:
 * 编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数（也被称为汉明重量）
 *
 * 思路:
 * n = n & (n - 1) 可以除去最右边的那位 1
 * 能循环几次就说明有几个1
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int i = 32;
        while(i--) {
            ans <<= 1;
            ans += n & 1;
            n >>= 1;
        }
        return ans;
    }
};