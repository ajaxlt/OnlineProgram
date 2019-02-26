#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 被围绕的区域(Surrounded Regions)
 *
 * 描述:
 * 给定一个二维的矩阵，包含 'X' 和 'O'(字母 O)
 * 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充
 *
 * 示例:
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 *
 * 运行你的函数后，矩阵变为：
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 *
 * 解释:
 * 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
 *
 * 思路:
 * 1. 从四条边出发，找到 'O'，利用 dfs 将所有连通的 'O' 改成 '?'
 * 2. 遍历矩阵，将 'O' 改成 'X'，将 '?' 改成 'O'
 */

class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j) {
        for (int g = 0; g < 4; ++g) {
            if (i + G[g][0] > 0 && i + G[g][0] < rows - 1 &&
                j + G[g][1] > 0 && j + G[g][1] < columns - 1 &&
                board[i + G[g][0]][j + G[g][1]] == 'O') {
                board[i + G[g][0]][j + G[g][1]] = '?';
                dfs(board, i + G[g][0], j + G[g][1]);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        rows = board.size(), columns = board[0].size();
        if (rows <= 2 || columns <= 2) return; // 2 * 2 以下一定不会被围

        for (int j = 1; j < columns - 1; ++j) {
            if (board[0][j] == 'O') dfs(board, 0, j); // 上
            if (board[rows - 1][j] == 'O') dfs(board, rows - 1, j); // 下
        }
        for (int i = 1; i < rows - 1; ++i) {
            if (board[i][columns - 1] == 'O') dfs(board, i, columns - 1); // 左
            if (board[i][0] == 'O') dfs(board, i, 0);// 右
        }

        for (int i = 1; i < rows - 1; ++i) {
            for (int j = 1; j < columns - 1; ++j) {
                if (board[i][j] == '?') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
private:
    int rows, columns;
    int G[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};