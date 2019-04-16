#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 组合总和II(Combination Sum II)
 *
 * 描述:
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合
 *
 * candidates 中的数字在每个组合中只能使用一次
 *
 * 说明:
 * 所有数字（包括目标数）都是正整数
 * 解集不能包含重复的组合
 *
 * 示例:
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 所求解集为:
 * [
 *  [1, 7],
 *  [1, 2, 5],
 *  [2, 6],
 *  [1, 1, 6]
 * ]
 *
 * 思路:
 * 回溯法, 加去重
*/
class Solution {
public:
    void backtrack(vector<vector<int>>& rlt, vector<int>& candidates, vector<int> tmp, int target, int cur, int sum) {
        if (sum == target) {
            rlt.push_back(tmp);
            return;
        }
        else{
            for (int i = cur; i < candidates.size(); ) {
                if (sum + candidates[i] > target) break;
                else {
                    tmp.push_back(candidates[i]);
                    backtrack(rlt, candidates, tmp, target, i + 1, sum + candidates[i]);
                    tmp.pop_back();
                }
                while(candidates[i] == candidates[++i]); // 去重
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.empty()) return {};
        vector<vector<int>> rlt;
        sort(candidates.begin(), candidates.end());
        backtrack(rlt, candidates, {}, target, 0, 0);
        return rlt;
    }
};