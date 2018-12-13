#include <iostream>
#include <string>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 数字序列中某一位的数字
 *
 * 描述:
 * 数字以 0123456789101112131415...的格式序列化到一个字符序列中
 * 在这个序列中，第5位(从0开始计数)是5，第13位是1，第19位是4等等
 * 请写一个函数，求任意第n位对应的数字
 *
 * 思路：
 * 1. Brute-Force
 * 2. 参照剑指offer 225 页
*/
class Solution {
public:
    int solve1(int n)
    {
        if (n < 0) throw ("Invalid input.");
        string seq = "";
        int i = 0;
        while(seq.size() < n + 1) {
            seq += to_string(i);
            ++i;
        }
        return seq[n] - '0';
    }
    int solve2(int n) {
        if (n < 0) throw ("Invalid input.");
        if (n < 10) return n;
        int cnt = 10, i = 2, len = 90;
        while(n > cnt + i * len) {
            cnt += i * len;
            ++i;
            len *= 10;
        }
        int base = len / 9, num = base + (n - cnt) / i, bit = (n - cnt) % i;
        return to_string(num)[bit] - '0';
    }
};
