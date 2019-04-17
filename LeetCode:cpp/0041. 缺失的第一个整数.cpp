#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 缺失的第一个正数(First Missing Positive)
 *
 * 描述:
 * 给定一个未排序的整数数组，找出其中没有出现的最小的正整数
 *
 * 示例 1:
 * 输入: [1,2,0]
 * 输出: 3
 *
 * 示例 2:
 * 输入: [3,4,-1,1]
 * 输出: 2
 *
 * 示例 3:
 * 输入: [7,8,9,11,12]
 * 输出: 1
 *
 * 思路:
 * 我们把数字里的数字重排
 * 第一次遍历，将范围在 1 ~ len 的数，放在 0 ~ len - 1 的位置上
 * 第二次遍历，第一个失位的正整数便是所求
 *
 * 这里，我们不会处理负数，以及大于len的数
 * 因为我们返回的最大值是len + 1
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty()) return 1;
        for (int i = 0; i < nums.size(); ) {
            if (nums[i] <= 0 || nums[i] > nums.size() || nums[nums[i] - 1] == nums[i]) ++i;
            else swap(nums[i], nums[nums[i] - 1]);
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) return i + 1;
        }
        return nums.size() + 1;
    }
};