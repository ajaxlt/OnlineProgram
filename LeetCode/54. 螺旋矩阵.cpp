#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 螺旋矩阵(Spiral Matrix)
 *
 * 描述:
 * 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
 *
 * 示例 1:
 * 输入:
 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 * 输出: [1,2,3,6,9,8,7,4,5]
 *
 * 示例 2:
 * 输入:
 * [
 *  [1, 2, 3, 4],
 *  [5, 6, 7, 8],
 *  [9,10,11,12]
 * ]
 * 输出: [1,2,3,4,8,12,11,10,9,5,6,7]
 *
 * 思路:
 * 数学题，找规律
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int > rlt;
        if (matrix.empty()) return rlt;
        int row = matrix.size(), column = matrix[0].size();

        if (row == 1) return matrix[0];
        else if (column == 1) {
            for (int i = 0; i < row; ++i) rlt.push_back(matrix[i][0]);
            return rlt;
        }

        else {
            int t = min((row - 1) / 2, (column - 1) / 2), cnt = 0; // 圈数
            for (int i = 0; i <= t; ++i) {
                for (int j = i; j < column - i; ++j) { // 上行
                    rlt.push_back(matrix[i][j]);
                    ++ cnt;
                }
                if (cnt == row * column) return rlt;
                for (int j = i + 1; j < row - i - 1; ++j) { // 右列
                    rlt.push_back(matrix[j][column - i - 1]);
                    ++cnt;
                }
                for (int j = column - i - 1; j >= i; --j) { // 下行
                    rlt.push_back(matrix[row - i - 1][j]);
                    ++cnt;
                }
                if (cnt == row * column) return rlt;
                for (int j = row - i - 2; j >= i + 1; --j) {
                    rlt.push_back(matrix[j][i]);
                    ++cnt;
                }
            }
            return rlt;
        }

    }
};