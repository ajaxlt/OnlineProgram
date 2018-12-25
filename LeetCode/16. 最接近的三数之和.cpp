#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 最接近的三数之和(3Sum Closest)
 *
 * 描述:
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target
 * 找出 nums 中的三个整数，使得它们的和与 target 最接近
 * 返回这三个数的和. 假定每组输入只存在唯一答案
 *
 * 思路:
 * 类似于 15.
 * 暴力法的复杂度是 n3，但如果预先排序的话的可以降为 n2
 *
 * 仍然需要 3 个指针, i, j, k, 其中 i 位于最外层
 * 当 i 取定后, 由于数组是排序的, 因此只要合适地取 j, k 的起点
 * 便可以将 j, k 处于一层遍历中
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int p = 0, len = nums.size();
        int res = nums[0] + nums[1] + nums[2];
        for(; p < len - 2; ++p) {
            int q = p + 1, r = len - 1;
            while(q < r) {
                int curRes = nums[p] + nums[q] + nums[r];
                if (abs(curRes - target) < abs(res - target)) res = curRes;
                if (curRes == target) return res;
                else if (curRes < target) ++q;
                else --r;
            }
        }
        return res;
    }
};