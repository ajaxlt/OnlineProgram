#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 搜索二维矩阵(Search a 2D Matrix)
 *
 * 描述:
 * 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
 *
 * 每行中的整数从左到右按升序排列。
 * 每行的第一个整数大于前一行的最后一个整数。
 *
 * 示例:
 * 输入:
 * matrix =
 * [
 *  [1,   3,  5,  7],
 *  [10, 11, 16, 20],
 *  [23, 30, 34, 50]
 * ]
 *
 * target = 3
 * 输出: true
 *
 * 思路:
 * 两次二分法
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int rows = matrix.size(), columns = matrix[0].size();

        int p = 0, r = rows - 1;
        while(p <= r) {
            int q = (p + r) / 2;
            if (matrix[q][columns - 1] == target) return true;
            else if (matrix[q][columns - 1] < target) p = q + 1;
            else r = q - 1;
        }
        int row = r + 1;
        if (row == rows) return false;
        p = 0, r = columns - 1;
        while(p <= r) {
            int q = (p + r) / 2;
            if (matrix[row][q] == target) return true;
            else if(matrix[row][q] < target) p = q + 1;
            else r = q - 1;
        }
        return false;
    }
};