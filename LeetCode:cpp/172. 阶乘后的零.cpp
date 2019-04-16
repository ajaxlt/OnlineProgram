#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 阶乘后的零(Factorial Trailing Zeroes)
 *
 * 描述:
 * 给定一个整数 n，返回 n! 结果尾数中零的数量。
 *
 * 思路:
 * 计算 5 的个数
 */
class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        long long base = 5;
        while(base <= n) {
            cnt += n / base;
            base *= 5;
        }
        return cnt;
    }
};