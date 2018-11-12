#include <iostream>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 二进制中1的个数
 *
 * 描述: 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
 *
 * 思路:
 * 二进制中1的妙用
*/
class Solution {
public:
    /**
     *  判断二进制的末位是否为1，可以用该二进制数 & 1
     *  1 << 1 可以用于判断倒数第二位是否为 1
     *  因此32位的整数循环32次即可
     */
    int NumberOf1_v1(int n) {
        int cnt = 0;
        unsigned int flag = 1;
        while(flag) {
            if (n & flag) ++cnt;
            flag = flag << 1;
        }
    }
    /**
     * 把一个整数与其减1的数作与运算
     * 则可以将该数的最右边一位由1变成0
     * 我们只要统计其可以经过几次该运算，便能得知其1的个数
     */
    int NumberOf1_v2(int n) {
        int cnt = 0;
        while(n) {
            n = n & (n - 1);
            ++cnt;
        }
        return cnt;
    }
};