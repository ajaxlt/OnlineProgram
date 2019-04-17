#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 乘积最大子序列(Maximum Product Subarray)
 *
 * 描述:
 * 给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）
 *
 * 示例 1:
 * 输入: [2,3,-2,4]
 * 输出: 6
 * 解释: 子数组 [2,3] 有最大乘积 6。
 *
 * 示例 2:
 * 输入: [-2,0,-1]
 * 输出: 0
 * 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 *
 * 思路:
 * 动态规划，同时保存最小和最大
 */

class Solution{
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];

        int len = nums.size(), Max;
        vector<pair<int, int>> dp(len);
        dp[0].first = nums[0], dp[0].second = nums[0];
        Max = dp[0].first;
        for (int i = 1; i < len; ++i) {
            //cout << nums[i] << endl;
            int tmp1 = nums[i] * dp[i - 1].first,
                    tmp2 = nums[i] * dp[i - 1].second;
            dp[i].first = tmp1 > tmp2 ? (tmp1 > nums[i] ? tmp1 : nums[i]) : (tmp2 > nums[i] ? tmp2 : nums[i]);
            dp[i].second = tmp1 < tmp2 ? (tmp1 < nums[i] ? tmp1 : nums[i]) : (tmp2 < nums[i] ? tmp2 : nums[i]);
            Max = Max > dp[i].first ? Max : dp[i].first;
        }
        return Max;
    }
};