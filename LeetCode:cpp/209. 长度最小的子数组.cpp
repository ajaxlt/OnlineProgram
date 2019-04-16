/*
 * 来源: LeetCode
 * 题目: 长度最小的子数组(Minimum Size Subarray Sum)
 *
 * 描述:
 * 给定一个含有 n 个正整数的数组和一个正整数 s
 * 找出该数组中满足其和 ≥ s 的长度最小的连续子数组
 * 如果不存在符合条件的连续子数组，返回 0
 *
 * 示例:
 * 输入: s = 7, nums = [2,3,1,2,4,3]
 *
 * 输出: 2
 * 解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
 *
 * 思路:
 * 双指针限定区间
 * 1. 如果当前和小于目标，右指针向后移
 * 2. 如果当前和大于目标，左指针向右移
 * 同时维护 最小长度
 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size();
        int i = -1, j = 0;
        int sum = 0, ans = len + 1;
        while(i < len && j < len) {
            if (sum < s) {
                if (i == len - 1) break;
                else sum += nums[++i];
            }
            else {
                ans = min(ans, i - j + 1);
                sum -= nums[j++];
            }
        }
        return ans == len + 1 ? 0 : ans;
    }
};