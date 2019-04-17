#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 搜索旋转排序数组(Search in Rotated Sorted Array)
 *
 * 描述:
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转
 * 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2]
 * 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1
 * 你可以假设数组中不存在重复的元素
 * 你的算法时间复杂度必须是 O(log n) 级别
 *
 * 思路:
 * 单边有序，分类讨论即可
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int p = 0, r = nums.size() - 1;
        while(p <= r) {
            int q = (p + r) / 2;
            if (nums[q] == target) return q;
            if (nums[q] >= nums[p]) { //左有序
                if (nums[q] >= target && nums[p] <= target) r = q - 1;
                else p = q + 1;
            } else { // 右有序
                if (nums[q] <= target && nums[r] >= target) p = q + 1;
                else r = q - 1;
            }
        }
        return -1;
    }
};