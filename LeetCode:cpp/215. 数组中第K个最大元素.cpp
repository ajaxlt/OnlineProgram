#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 数组中的第K个最大元素(Kth Largest Element in an Array)
 *
 * 描述:
 * 在未排序的数组中找到第 k 个最大的元素
 *
 * 思路:
 * 快速排序
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