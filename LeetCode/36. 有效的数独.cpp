#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 有效的数独(Valid Sudoku)
 *
 * 描述:
 * 判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可
 * 数字 1-9 在每一行只能出现一次
 * 数字 1-9 在每一列只能出现一次
 * 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次
 *
 * 思路:
 * 嵌套矩阵的循环
*/
class Solution {
public:
    const int Max = 9;
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size();
        if (row != Max) return false;
        int column = board[0].size();
        if (column != Max) return false;

        bool use[Max + 1];
        int i, j;
        // check row
        for (i = 0; i < Max; ++i) {
            memset(use, false, sizeof(use));
            for (j = 0; j < Max; ++j) {
                if (board[i][j] == '.') continue;
                else if (use[board[i][j] - '0']) return false;
                else use[board[i][j] - '0'] = true;
            }
        }
        // check column
        for (j = 0; j < Max; ++j) {
            memset(use, false, sizeof(use));
            for (i = 0; i < Max; ++i) {
                if (board[i][j] == '.') continue;
                else if (use[board[i][j] - '0']) return false;
                else use[board[i][j] - '0'] = true;
            }
        }
        // check Sudoku
        for (i = 0; i < Max; i+=3) {
            for (j = 0; j < Max; j+=3) {
                memset(use, false, sizeof(use));
                for (int m = 0; m < 3; ++m) {
                    for (int n = 0; n < 3; ++n) {
                        if (board[i + m][j + n] == '.') continue;
                        else if (use[board[i + m][j + n] - '0']) return false;
                        else use[board[i + m][j + n] - '0'] = true;
                    }
                }
            }
        }
        return true;
    }
};