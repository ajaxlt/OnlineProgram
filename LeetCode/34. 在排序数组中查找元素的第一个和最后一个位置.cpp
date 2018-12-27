#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 在排序数组中查找元素的第一个和最后一个位置(Find First and Last Position of Element in Sorted Array)
 *
 * 描述:
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置
 * 你的算法时间复杂度必须是 O(log n) 级别
 * 如果数组中不存在目标值，返回 [-1, -1]
 *
 * 思路:
 * 2次二分法
*/
class Solution {
public:
    int binarySearch(const vector<int>& nums, int p, int r, int target, int flag){
        if (p > r) return -1;
        int q = (p + r) / 2;
        if (nums[q] == target) {
            int next = flag ? binarySearch(nums, p, q - 1, target, flag) :
                       binarySearch(nums, q + 1, r, target, flag);
            return next == -1 ? q : next;
        }
        else if (nums[q] > target) return binarySearch(nums, p, q - 1, target, flag);
        else return binarySearch(nums, q + 1, r, target, flag);
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {binarySearch(nums, 0, nums.size() - 1, target, 1),
                binarySearch(nums, 0, nums.size() - 1, target, 0)};
    }
};