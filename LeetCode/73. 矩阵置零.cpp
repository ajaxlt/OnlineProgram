#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 矩阵置零(Set Matrix Zeroes)
 *
 * 描述:
 * 给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法
 *
 * 示例 1:
 * 输入:
 * [
 *  [1,1,1],
 *  [1,0,1],
 *  [1,1,1]
 * ]
 *
 * 输出:
 * [
 *  [1,0,1],
 *  [0,0,0],
 *  [1,0,1]
 * ]
 *
 * 示例 2:
 * 输入: [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 *
 * 输出:
 * [
 *  [0,0,0,0],
 *  [0,4,5,0],
 *  [0,3,1,0]
 * ]
 *
 * 思路:
 * 构造vis数组
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& mat, vector<vector<bool>>& vis, int i, int j) {
        for (int k = 0; k < columns; ++k) {
            if (mat[i][k]) vis[i][k] = true;
            mat[i][k] = 0;
        }
        for (int k = 0; k < rows; ++k) {
            if (mat[k][j]) vis[k][j] = true;
            mat[k][j] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        rows = matrix.size(), columns = matrix[0].size();
        vector<vector<bool>> vis(rows, vector<bool>(columns, false));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (matrix[i][j] == 0 && !vis[i][j]) {
                    setZeroes(matrix, vis, i, j);
                }
            }
        }
    }
private:
    int rows, columns;
};