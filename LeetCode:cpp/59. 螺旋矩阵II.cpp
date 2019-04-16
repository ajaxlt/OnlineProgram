#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 螺旋矩阵II(Spiral Matrix II)
 *
 * 描述:
 * 给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵
 *
 * 示例:
 * 输入: 3
 * 输出:
 * [
 *  [ 1, 2, 3 ],
 *  [ 8, 9, 4 ],
 *  [ 7, 6, 5 ]
 * ]
 *
 * 思路:
 * 类似54.
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> tmp(n, 0);
        vector<vector<int>> rlt(n ,tmp);
        int t = n - 1 / 2, cur = 1;
        for (int i = 0; i <= t; ++i) {
            for (int j = i; j < n - i; ++j) { // 上行
                rlt[i][j] = cur++;
            }
            if (cur == n * n + 1) return rlt;
            for (int j = i + 1; j < n - i - 1; ++j) { // 右列
                rlt[j][n - i - 1] = cur++;
            }
            for (int j = n - i - 1; j >= i; --j) { // 下行
                rlt[n - i - 1][j] = cur++;
            }
            if (cur == n * n + 1) return rlt;
            for (int j = n - i - 2; j >= i + 1; --j) {
                rlt[j][i] = cur++;
            }
        }
        return rlt;
    }
};