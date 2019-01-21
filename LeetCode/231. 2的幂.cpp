#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 2的幂(Power of Two)
 *
 * 描述:
 * 给定一个整数，编写一个函数来判断它是否是 2 的幂次方
 *
 * 思路:
 * 简单题，注意 0 的判断
 */


class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        while(n % 2 == 0) n /= 2;
        return n == 1;
    }
};