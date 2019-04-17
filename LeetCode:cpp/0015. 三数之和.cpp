#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 三数之和(3Sum)
 *
 * 描述:
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组
 *
 * 思路:
 * 注意去重
 *
 * 1. 排序
 * 2. 3指针, i 处于最外层
 * 3. j = i + 1, k = end，可以根据微调 j, k 使得a[j] + a[k] 逼近 -a[i]
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); // 排序
        if (nums.empty() || nums.back() < 0 || nums.front() > 0) return {};//去除垃圾
        for (int k = 0; k < nums.size(); ++k) {
            if (nums[k] > 0) break; // 如果最小的都大于0了，肯定不可能再有了
            if (k > 0 && nums[k] == nums[k - 1]) continue;// 去重
            int target = 0 - nums[k];
            int i = k + 1, j = nums.size() - 1;// 双指针
            while (i < j) {
                if (nums[i] + nums[j] == target) {
                    ans.push_back({nums[k], nums[i], nums[j]});
                    while (i < j && nums[i] == nums[i + 1]) ++i;// 去重
                    while (i < j && nums[j] == nums[j - 1]) --j;
                    ++i; --j;
                } else if (nums[i] + nums[j] < target) ++i;
                else --j;
            }
        }
        return ans;
    }
};