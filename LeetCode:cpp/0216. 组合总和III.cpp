#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 组合总和III(Combination Sum III)
 *
 * 描述:
 * 找出所有相加之和为 n 的 k 个数的组合
 * 组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字
 *
 * 说明：
 * 所有数字都是正整数
 * 解集不能包含重复的组合。
 *
 * 示例 1:
 * 输入: k = 3, n = 7
 * 输出: [[1,2,4]]
 *
 * 示例 2:
 * 输入: k = 3, n = 9
 * 输出: [[1,2,6], [1,3,5], [2,3,4]]
 *
 * 思路:
 * 回溯
 */

class Solution {
public:
    void backtrack(int back, int cur_tot, int cur_sum) {
        if (cur_tot + 1 == tot) {
            if (sum - cur_sum > back && sum - cur_sum <= 9) {
                tmp.push_back(sum - cur_sum);
                ans.push_back(tmp);
                tmp.pop_back();
            }
        }
        else {
            for (int i = back + 1; i <= 9; ++i) {
                tmp.push_back(i);
                backtrack(i, cur_tot + 1, cur_sum + i);
                tmp.pop_back();
            }

        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        tot = k, sum = n;
        if (tot * 8 < sum) return ans;
        for (int i = 1; i <= 9; ++i) {
            tmp.push_back(i);
            backtrack(i, 1, i);
            tmp.pop_back();
        }

        return ans;
    }
private:
    vector<int> tmp;
    vector<vector<int>> ans;
    int tot, sum;
};