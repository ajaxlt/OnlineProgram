#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 子集II(Subsets II)
 *
 * 描述:
 * 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 *
 * 说明：解集不能包含重复的子集。
 *
 * 示例:
 * 输入: [1,2,2]
 * 输出:
 * [
 *  [2],
 *  [1]，
 *  [1,2,2],
 *  [2,2],
 *  [1,2],
 *  []
 * ]
 *
 * 思路:
 * 回溯法
 */


class Solution {
public:
    void backtrack(const vector<int>& nums, vector<int> tmp, int i, int len) {
        //cout << i << " " << len << endl;
        if (tmp.size() == len) {
            ans.push_back(tmp);
            if (len == 0) backtrack(nums, tmp, 0, 1);
        }
        else {
            if (nums.size() - i + tmp.size() < len) return;
            for (int j = i; j < nums.size(); ++j) {
                tmp.push_back(nums[j]);
                backtrack(nums, tmp, j + 1, len);
                tmp.pop_back();

                while(j + 1 < nums.size() && nums[j + 1] == nums[j]) ++j;

            }
            if (tmp.size() == 0 && len < nums.size()) backtrack(nums, tmp, 0, len + 1);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, tmp, 0, 0);
        return ans;
    }
private:
    vector<int> tmp;
    vector<vector<int>> ans;
};