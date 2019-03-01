#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 寻找旋转排序数组中的最小值(Find Minimum in Rotated Sorted Array)
 *
 * 描述:
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转
 * ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )
 *
 * 请找出其中最小的元素
 * 你可以假设数组中不存在重复元素
 *
 * 示例 1:
 * 输入: [3,4,5,1,2]
 * 输出: 1
 *
 * 示例 2:
 * 输入: [4,5,6,7,0,1,2]
 * 输出: 0
 *
 * 思路:
 * 变形二分
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int Min = nums[0];
        int head = 0, tail = nums.size() - 1;
        while (head <= tail) {
            int mid = (head + tail) / 2;
            if (nums[mid] >= nums[head]) {
                Min = min(Min, nums[head]);
                head = mid + 1;
            } else {
                Min = min(Min, nums[mid]);
                tail = mid - 1;
            }
        }
        return Min;
    }
};