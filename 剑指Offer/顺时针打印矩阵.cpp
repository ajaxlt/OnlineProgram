#include <iostream>
#include <vector>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 顺时针打印矩阵
 *
 * 描述: 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字
 *
 * 思路:
 * 可以用循环或者递归实现，循环需要手动计算边界
 * 瞬时针可以转换成四个方向逐一处理，但务必考虑单行单列以及单元素的特别处理
 *
*/


class Solution {
public:
    /**
     * @brief 单圈打印函数（递归定义）
     * @param[in] matrix 给定矩阵
     * @param[in,out] rlt 结果存放
     * @param[in] t 第 t 圈 (t >= 0)
     *
     */
    void printOneCircle(vector<vector<int> > matrix, vector<int>& rlt, int t) {
        int rows = matrix.size(); // 总行数
        int columns = matrix[0].size(); // 总列数
        if (t * 2 >= rows || t * 2 >= columns) return;
        if (t == columns - t - 1) { //只有一列
            for (int i = t; i < rows - t; ++i) rlt.push_back(matrix[i][t]);
            return;
        }
        if (t == rows - t - 1) { //只有一行
            for (int j = t; j < columns - t; ++j) rlt.push_back(matrix[t][j]);
            return;
        }

        //所有方向取值都采用左闭右开
        for (int j = t; j < columns - t - 1; ++j) rlt.push_back(matrix[t][j]); // 上行
        for (int i = t; i < rows - t - 1; ++i) rlt.push_back(matrix[i][columns - t - 1]); // 右列
        for (int j = columns - t - 1; j > t; --j) rlt.push_back(matrix[rows - t - 1][j]); // 下行
        for (int i = rows - t - 1; i > t; --i) rlt.push_back(matrix[i][t]); // 下行
        printOneCircle(matrix, rlt, ++t);
    }
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> rlt;
        if(!matrix.empty()) printOneCircle(matrix, rlt, 0);
        return rlt;
    }
};