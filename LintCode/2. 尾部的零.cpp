/*
 * 来源: LintCode
 * 题目: 尾部的零
 *
 * 描述:
 * 设计一个算法，计算出n阶乘中尾部零的个数
 *
 * 思路:
 * 只有因子 2, 5 能够生成 0, 而 2 一定比 5, 因此只统计 5 的个数即可
 * 先统计含有 5 的个数
 * .. 25 的个数.. 125 ...
*/
class Solution {
public:
    /*
     * @param n: A long integer
     * @return: An integer, denote the number of trailing zeros in n!
     */
    long long trailingZeros(long long n) {
        // write your code here, try to do it without arithmetic operators.
        long long cnt = 0;
        long long base = 5; // 计算5的个数
        while(base <= n) {
            cnt += n / base;
            base *= 5;
        }
        return cnt;
    }
};