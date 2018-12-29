#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 最大子序和(Maximum Subarray)
 *
 * 描述:
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和
 *
 * 示例:
 * 输入: [-2,1,-3,4,-1,2,1,-5,4],
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6
 *
 * 思路:
 * 最简单的dp
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return NULL;
        if (nums.size() == 1) return nums[0];
        const int len = nums.size();
        int dp[len];
        dp[0] = nums[0];
        int Max = dp[0];
        for (int i = 1; i < len; ++i) {
            if (dp[i - 1] < 0) dp[i] = nums[i];
            else dp[i] = dp[i - 1] + nums[i];
            Max = max(Max, dp[i]);
        }
        return Max;
    }
};