#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 打家劫舍(House Robber)
 *
 * 描述:
 * 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统
 * 如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额
 *
 * 思路:
 * 隔一个求数组和最大，动态规划
 * 假定 dp[i] 表示 以 i 结尾的和最大
 * 则 dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
 * 即，要么当前的 i 不取，此时dp[i] = dp[i - 1]
 * 要么当前的 i 取，此时dp[i] = dp[i - 2] + nums[i]
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        if (len == 1) return nums[0];
        vector<int> dp(len);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < len; ++i)
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        return dp[len - 1];
    }
};