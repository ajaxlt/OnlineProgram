#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 解数独(Sudoku Solver)
 *
 * 描述:
 * 编写一个程序，通过已填充的空格来解决数独问题
 *
 * 思路:
 * 结合36. 回溯
*/
class Solution {
public:
    const int Max = 9;
    bool flag = false;
    void printInfo(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); ++i) {
            cout << endl;
            for (int j = 0; j < board[i].size(); ++j)
                cout << board[i][j] << " ";
        }
    }
    bool check(vector<vector<char>>& board, int i, int j, int tar) {
        int k;
        // check row
        for (k = 0; k < Max; ++k) {
            if (board[i][k] == '.') continue;
            if (tar == board[i][k] - '0') return false;
        }
        // check column
        for (k = 0; k < Max; ++k) {
            if (board[k][j] == '.') continue;
            if (tar == board[k][j] - '0') return false;
        }

        // check Sudoku
        int sub_i = i / 3 * 3, sub_j = j / 3 * 3;
        for (int m = sub_i; m < sub_i + 3; ++m) {
            for (int n = sub_j; n < sub_j + 3; ++n) {
                if (board[m][n] == '.') continue;
                if (tar == board[m][n] - '0') return false;
            }
        }
        return true;
    }
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i == Max) flag = true;
        else {
            if (board[i][j] != '.') {
                if (j == Max - 1) dfs(board, i + 1, 0);
                else dfs(board, i, j + 1);
            }
            else {
                for (int a = 1; a <= 9; ++a) {
                    if (check(board, i, j, a)) { //如果可以加

                        board[i][j] = a + '0';
                        if (j == Max - 1) dfs(board, i + 1, 0);
                        else dfs(board, i, j + 1);

                        if (flag) return;
                        board[i][j] = '.'; // 回溯
                    }
                }
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0 ,0);
        //printInfo(board);
    }
};