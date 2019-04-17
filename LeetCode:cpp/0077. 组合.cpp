#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 组合(Combinations)
 *
 * 描述:
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 *
 * 示例:
 * 输入: n = 4, k = 2
 * 输出:
 * [
 *  [2,4],
 *  [3,4],
 *  [2,3],
 *  [1,2],
 *  [1,3],
 *  [1,4]
 * ]
 *
 * 思路:
 * 回溯法
*/
class Solution {
public:
    void combine(int n, int k, int i, int j, vector<int> tmp) {
        if (i == k + 1) ans.push_back(tmp);
        else {
            for (int m = j; m <= n; ++m) {
                tmp.push_back(m);
                combine(n, k, i + 1, m + 1, tmp);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        if (n >= k) combine(n, k, 1, 1, {});
        return ans;
    }
private:
    vector<vector<int>> ans;
};