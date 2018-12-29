#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: Pow(x, n)(Pow(x, n))
 *
 * 描述:
 * 实现 pow(x, n) ，即计算 x 的 n 次幂函数
 *
 * 思路:
 * 二分法
*/

class Solution {
public:
    double myPow(double x, long n) {
        if (n == 0 || x == 1.0) return 1.0;
        else if (n == 1) return  x;

        if(n < 0) {
            x = 1 / x;
            n = -n;
        }
        double rlt = myPow(x, n / 2);
        if (n % 2 == 0) return rlt * rlt;
        else return x * rlt * rlt;
    }
};