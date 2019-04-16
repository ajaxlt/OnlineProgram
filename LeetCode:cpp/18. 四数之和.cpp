#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 四数之和(4Sum)
 *
 * 描述:
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？
 * 找出所有满足条件且不重复的四元组。
 *
 * 注意：
 * 答案中不可以包含重复的四元组。
 *
 * 示例：
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0
 * 满足要求的四元组集合为：
 * [
 *   [-1,  0, 0, 1],
 *   [-2, -1, 1, 2],
 *   [-2,  0, 0, 2]
 * ]
 *
 *
 * 思路:
 * 与15. 三数之和换汤不换药
 *
 * 我们可以推论， m 数之和的复杂度不大于 n ^ (m - 1)
 * 最里面的一层循环可以同时遍历2个数
 *
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> rlt;
        if (nums.size() < 4) return rlt;
        sort(nums.begin(), nums.end()); //排序
        for (int beg = 0; beg < nums.size() - 3; ++beg) { // 最外层循环
            if (beg != 0 && nums[beg] == nums[beg - 1]) continue; // 避重
            for (int sec = beg + 1; sec < nums.size() - 2; ++sec) { // 次外层循环
                if (sec != beg + 1 && nums[sec] == nums[sec - 1]) continue; // 避重
                int left = sec + 1, right = nums.size() - 1; // 内层循环包含2个指针
                while(left < right) {
                    int tmp = nums[beg] + nums[sec] + nums[left] + nums[right];
                    if (tmp == target) {
                        rlt.push_back({nums[beg], nums[sec], nums[left], nums[right]});
                        while(left < right && nums[left] == nums[left + 1]) ++left;
                        while(left < right && nums[right] == nums[right - 1]) --right;
                        ++left;
                        --right;
                    }
                    else if (tmp > target) {// 大了，right左移
                        --right;
                    }
                    else {
                        ++left;
                    }
                }
            }
        }
        return rlt;
    }
};