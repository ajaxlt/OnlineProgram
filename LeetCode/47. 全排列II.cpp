#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 全排列II(Permutations II)
 *
 * 描述:
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列
 *
 * 示例:
 * 输入: [1,1,2]
 * 输出:
 * [
 *  [1,1,2],
 *  [1,2,1],
 *  [2,1,1]
 *  ]
 *
 * 思路:
 * 46的基础上 + 去重
*/
class Solution {
public:
    void permutation(vector<int>& nums, int i) {
        if (i == nums.size()) ans.push_back(nums);

        set<int> mySet;
        for(int j = i; j < nums.size(); ++j) {
            if (mySet.count(nums[j])) continue;
            else mySet.insert(nums[j]);
            swap(nums[i], nums[j]);
            permutation(nums, i + 1);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.empty()) return {};
        permutation(nums, 0);
        return ans;
    }
private:
    vector<vector<int>> ans;
};