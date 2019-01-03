#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 爬楼梯(Climbing Stairs)
 *
 * 描述:
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 *
 * 思路:
 * 斐波那契数列
*/
class Solution {
public:
    int climbStairs(int n) {
        vector<int> F(n + 1, 0);
        F[0] = 1;
        F[1] = 1;
        for(int i = 2; i <= n; ++i) F[i] = F[i - 1] + F[i - 2];
        return F[n];
    }
};