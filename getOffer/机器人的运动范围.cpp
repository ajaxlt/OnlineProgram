#include <iostream>
#include <string.h>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 机器人的运动范围
 *
 * 描述: 地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
 * 但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18
 * 而且它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
 *
 * 思路: dfs
 */
class Solution {
public:
    // 题目中的阈值判断
    int getDigitSum(int row, int col) {
        int sum = 0;
        while (row) {
            sum += row % 10;
            row /= 10;
        }
        while(col) {
            sum += col % 10;
            col /= 10;
        }
        return sum;
    }
    // 判断是否可以走
    bool check(int threshold, bool* vis, int rows, int cols, int row, int col) {
        return
        row >= 0 && row < rows &&
        col >= 0 && col < cols &&
        !vis[row * cols + col] &&
        getDigitSum(row, col) <= threshold;
    }
    // 暴力深搜
    int dfs(int threshold, bool* vis, int rows, int cols, int row, int col) {
        int cnt = 0;
        if (check(threshold, vis, rows, cols, row, col)) {
            vis[row * cols + col] = true;
            //cout << row << " " << col << endl;
            cnt = 1 + dfs(threshold, vis, rows, cols, row + 1, col)
            + dfs(threshold, vis, rows, cols, row - 1, col)
            + dfs(threshold, vis, rows, cols, row, col + 1)
            + dfs(threshold, vis, rows, cols, row, col - 1);
        }
        return cnt;
    }
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold < 0 || rows <= 0 || cols <= 0) return 0; // 特殊输入判断
        bool* vis = new bool[rows * cols]; // 指针式开辟数组
        memset(vis, false, rows * cols);
        int cnt = dfs(threshold, vis, rows, cols, 0, 0);
        
        delete[] vis;
        return cnt;
    }
};

// 测试函数
int main() {
    Solution s;
    cout << s.movingCount(5, 10, 10) << endl;
}

