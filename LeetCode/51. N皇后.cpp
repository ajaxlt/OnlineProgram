#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: N皇后(N-Queens)
 *
 * 思路:
 * dfs
*/

class Solution {
public:
    bool check(vector<string>& tmp, int i, int j, int n) {
        // 检查列
        for (int k = 0; k < n; ++k) {
            if (k != i && tmp[k][j] == 'Q') return false;
        }
        // 检查对角线
        int k = 1;
        while (i + k < n && j + k < n){
            if (tmp[i + k][j + k] == 'Q') return false;
            ++ k;
        }
        k = 1;
        while(i - k >= 0 && j - k >= 0) {
            if (tmp[i - k][j - k] == 'Q') return false;
            ++k;
        }
        k = 1;
        while(i - k >= 0 && j + k < n) {
            if (tmp[i - k][j + k] == 'Q') return false;
            ++k;
        }
        k = 1;
        while(i + k < n && j - k >= 0) {
            if (tmp[i + k][j - k] == 'Q') return false;
            ++k;
        }
        return true;
    }
    void backtrack(vector<vector<string>>& rlt, vector<string>& tmp, int n, int i) {
        if (i == n) rlt.push_back(tmp);
        else {
            for (int j = 0; j < n; ++j) {
                if (check(tmp, i, j, n)) {
                    tmp[i][j] = 'Q';
                    backtrack(rlt, tmp, n, i + 1);
                    tmp[i][j] = '.';
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> rlt;
        if (n == 1) return {{"Q"}};
        if (n <= 3) return rlt;

        string ori = "";
        for (int i = 0; i < n; ++i) ori.push_back('.');
        vector<string> tmp(n, ori);
        backtrack(rlt, tmp, n, 0);

        return rlt;
    }
};