#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: x 的平方根(Sqrt(x))
 *
 * 描述:
 * 实现 int sqrt(int x) 函数
 * 计算并返回 x 的平方根，其中 x 是非负整数
 * 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去
 *
 * 思路:
 * 牛顿迭代法
*/
class Solution {
public:
    int mySqrt(long x) {
        if (!x) return 0;
        long t = x;
        while(true){
            t = (t + x / t) / 2;
            if (t * t <= x && (t + 1) * (t + 1) > x) return t;
        }
    }
};