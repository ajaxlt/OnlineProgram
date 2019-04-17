#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 单词搜索(Word Search)
 *
 * 描述:
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 *
 * 示例:
 * board =
 * [
 *  ['A','B','C','E'],
 *  ['S','F','C','S'],
 *  ['A','D','E','E']
 * ]
 *
 * 给定 word = "ABCCED", 返回 true.
 * 给定 word = "SEE", 返回 true.
 * 给定 word = "ABCB", 返回 false.
 *
 * 思路:
 * 回溯法
*/
class Solution {
public:
    bool dfs(vector<vector<char>>& board, const string& word, int i, int j, int k) {
        if (k == word.size() - 1) return true;
        else {
            char tmp = board[i][j];
            board[i][j] = '?';
            bool flag =
                    i - 1 >= 0 && board[i - 1][j] == word[k + 1] && dfs(board, word, i - 1, j, k + 1) ||
                    i + 1 < rows && board[i + 1][j] == word[k + 1] &&  dfs(board, word, i + 1, j, k + 1) ||
                    j - 1 >= 0 && board[i][j - 1] == word[k + 1] &&  dfs(board, word, i, j - 1, k + 1) ||
                    j + 1 < columns && board[i][j + 1] == word[k + 1] &&  dfs(board, word, i, j + 1, k + 1);
            board[i][j] = tmp;
            return flag;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;
        rows = board.size(), columns = board[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
private:
    int rows, columns;
};