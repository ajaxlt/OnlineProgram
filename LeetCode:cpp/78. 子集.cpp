#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 子集(Subsets)
 *
 * 描述:
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 说明：解集不能包含重复的子集。
 *
 * 示例:
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 *  [3],
 *  [1],
 *  [2],
 *  [1,2,3],
 *  [1,3],
 *  [2,3],
 *  [1,2],
 *  []
]
 *
 * 思路:
 * 回溯法， 78.的基础上加一个for
*/
class Solution {
public:
    void subsets(int n, int k, int i, int j, const vector<int>& nums, vector<int> tmp) {
        if (i == k) ans.push_back(tmp);
        else {
            for (int m = j; m < n; ++m) {
                tmp.push_back(nums[m]);
                subsets(n, k, i + 1, m + 1, nums, tmp);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        for (int k = 0; k <= nums.size(); ++k) {
            subsets(nums.size(), k, 0, 0, nums, {});
        }
        return ans;
    }
private:
    vector<vector<int>> ans;
};