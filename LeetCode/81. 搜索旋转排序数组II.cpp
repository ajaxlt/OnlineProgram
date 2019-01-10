#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 搜索旋转排序数组II(Search in Rotated Sorted Array II)
 *
 * 描述:
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转
 * ( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )
 * 编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false
 *
 * 示例 1:
 * 输入: nums = [2,5,6,0,0,1,2], target = 0
 * 输出: true
 *
 * 示例 2:
 * 输入: nums = [2,5,6,0,0,1,2], target = 3
 * 输出: false
 *
 * 思路:
 * 对于之前的题目，数组是不重复的
 * 比如，[4,5,1,2,3] mid = 2, 我们可以比较nums[p] 和 nums[mid] 以判断数组是左有序还是右有序的
 * 但是，如果重复，nums[p] 可以 等于 nums[mid]
 * 我们将这种情况切出，并使 p += 1
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
        int p = 0, r = nums.size() - 1;
        while (p <= r) {
            int q = (p + r) / 2;
            if (nums[q] == target) return true;
            if (nums[q] > nums[p]) { //左有序
                if (nums[q] > target && nums[p] <= target) r = q - 1;
                else p = q + 1;
            } else if (nums[q] < nums[p]){ // 右有序
                if (nums[q] < target && nums[r] >= target) p = q + 1;
                else r = q - 1;
            } else ++p;
        }
        return false;
    }
};