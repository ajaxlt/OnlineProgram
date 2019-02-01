#include <iostream>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 三角形最小路径和(Triangle)
 *
 * 描述:
 * 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
 *
 * 例如，给定三角形：
 * [
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
  ]

  自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）
 *
 * 思路:
 * 原地动态规划
 *
 */

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans = triangle[0][0];
        for (int i = 1; i < triangle.size(); ++i) {
            ans += triangle[i][0];
            for (int j = 0; j < triangle[i].size(); ++j) {
                if (j == 0) triangle[i][j] += triangle[i - 1][j];
                else if (j == triangle[i].size() - 1)
                    triangle[i][j] += triangle[i - 1][j - 1];
                else triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
                if (i == triangle.size() - 1) ans = min(ans, triangle[i][j]);
            }
        }
        return ans;
    }
};