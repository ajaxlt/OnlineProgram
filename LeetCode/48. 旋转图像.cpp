#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 旋转图像(Rotate Image)
 *
 * 描述:
 * 给定一个 n × n 的二维矩阵表示一个图像
 * 将图像顺时针旋转 90 度
 *
 * 说明：
 * 你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
 *
 * 示例 1:
 * 给定 matrix =
 * [
 *  [1,2,3],
 *  [4,5,6],
 *  [7,8,9]
 * ]
 *
 * 原地旋转输入矩阵，使其变为:
 * [
 *  [7,4,1],
 *  [8,5,2],
 *  [9,6,3]
 * ]
 *
 * 思路:
 * 数学找规律
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix.size() == 1) return ;
        int m = matrix.size();
        int i = 0, tmp, tmp2;
        while(m - 2 * i > 1) {
            for (int j = i; j < m - i - 1; ++j) {
                // i ,j;
                int cur_i = i, cur_j = j;
                tmp = matrix[cur_i][cur_j];
                for (int k = 0; k < 4; ++k) {
                    int tmp_i = cur_i;
                    cur_i = cur_j;
                    cur_j = m - tmp_i - 1;

                    // 双值改变，注意变换
                    tmp2 = matrix[cur_i][cur_j];
                    //cout << matrix[cur_i][cur_j] << "->" << tmp << endl;
                    matrix[cur_i][cur_j] = tmp;
                    tmp = tmp2;
                }
            }
            ++ i;
        }
    }
};