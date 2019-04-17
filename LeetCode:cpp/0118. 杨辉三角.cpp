#include <iostream>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 杨辉三角(Pascal's Triangle)
 *
 * 描述:
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行
 *
 * 示例:
 * 输入: 5
 * 输出:
 * [
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
 ]
 * 思路:
 * 简单题
 *
 */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; ++i) {
            vector<int> tmp(i + 1, 1);

            for (int j = 1; j <= i / 2; ++j) {
                tmp[j] = ans[i - 1][j - 1] + ans[i - 1][j];
                tmp[i - j] = tmp[j];
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};