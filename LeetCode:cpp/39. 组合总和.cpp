#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 组合总数(Combination Sum)
 *
 * 描述:
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合
 *
 * candidates 中的数字可以无限制重复被选取。
 *
 * 说明:
 * 所有数字（包括 target）都是正整数
 * 解集不能包含重复的组合
 *
 * 示例:
 * 输入: candidates = [2,3,6,7], target = 7,
 * 所求解集为:
 * [
 *  [7],
 *  [2,2,3]
 * ]
 *
 * 思路:
 * 回溯法
*/
class Solution {
public:
    void backtrack(vector<vector<int>>& rlt, vector<int>& candidates, vector<int> tmp, int target, int cur, int sum) {
        if (sum == target) {
            rlt.push_back(tmp);
            return;
        }
        else{
            for (int i = cur; i < candidates.size(); ++i) {
                if (sum + candidates[i] > target) break;
                else {
                    tmp.push_back(candidates[i]);
                    backtrack(rlt, candidates, tmp, target, i, sum + candidates[i]);
                    tmp.pop_back();
                }
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.empty()) return {};
        vector<vector<int>> rlt;
        sort(candidates.begin(), candidates.end());
        backtrack(rlt, candidates, {}, target, 0, 0);
        return rlt;
    }
};