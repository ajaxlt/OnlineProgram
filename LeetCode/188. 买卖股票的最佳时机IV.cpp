#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 买卖股票的最佳时机IV(Best Time to Buy and Sell Stock IV)
 *
 * 描述:
 * 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格
 * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易
 * 注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）
 *
 *
 * 思路:
 * 1. 如果 k > prices.size() / 2, 采用 II 的贪心算法(一涨就卖)
 * 2. 否则, 采用 III 的推广
*/


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k >= prices.size()) {
            int ans = 0;
            for (int i = 1; i < prices.size(); ++i) {
                if (prices[i] > prices[i - 1])
                    ans += prices[i] - prices[i - 1];
            }
            return ans;
        }
        else {
            vector<int> hold(k + 1, INT32_MIN);
            vector<int> sold(k + 1, 0);

            for (int i : prices) {
                for (int j = 1; j <= k; ++j) {
                    hold[j] = max(hold[j], sold[j - 1] - i);
                    sold[j] = max(sold[j], hold[j] + i);
                }
            }

            return sold[k];
        }
    }
};