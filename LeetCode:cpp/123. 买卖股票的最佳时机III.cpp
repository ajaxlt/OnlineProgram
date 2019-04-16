#include <iostream>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 买卖股票的最佳时机III(Best Time to Buy and Sell Stock III)
 *
 * 描述:
 *
 * 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格
 * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
 *
 * 思路:
 * 维护四个变量
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold1 = INT32_MIN, hold2 = INT32_MIN;
        int sold1 = 0, sold2 = 0;
        // 假设一开始一分钱没有, 如果以 i 价格买进，那么资金便是 -i;
        for (int i : prices) {
            hold1 = max(hold1, -i);
            sold1 = max(sold1, hold1 + i);
            hold2 = max(hold2, sold1 - i);
            sold2 = max(sold2, hold2 + i);
        }
        return sold2;
    }
};