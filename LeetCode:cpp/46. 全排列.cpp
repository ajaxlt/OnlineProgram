#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 全排列(Permutations)
 *
 * 描述:
 * 给定一个没有重复数字的序列，返回其所有可能的全排列
 *
 * 示例:
 * 输入: [1,2,3]
 * 输出:
 * [
 *  [1,2,3],
 *  [1,3,2],
 *  [2,1,3],
 *  [2,3,1],
 *  [3,1,2],
 *  [3,2,1]
 * ]
 *
 * 思路:
 * 递归
*/
class Solution {
public:
    void permutation(vector<int>& nums, int i) {
        if (i == nums.size()) ans.push_back(nums);
        for(int j = i; j < nums.size(); ++j) {
            swap(nums[i], nums[j]);
            permutation(nums, i + 1);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) return {};
        permutation(nums, 0);
        return ans;
    }
private:
    vector<vector<int>> ans;
};