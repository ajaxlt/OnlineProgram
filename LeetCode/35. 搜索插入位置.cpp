#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 搜索插入位置(Search Insert Position)
 *
 * 描述:
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引
 * 如果目标值不存在于数组中，返回它将会被按顺序插入的位置
 * 你可以假设数组中无重复元素
 *
 * 思路:
 * 二分法
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        int beg = 0, end = nums.size() - 1;
        while(end >= beg) {
            int mid = (beg + end) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) end = mid - 1;
            else beg = mid + 1;
        }
        return beg;
    }
};