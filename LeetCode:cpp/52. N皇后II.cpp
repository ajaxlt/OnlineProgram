#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: N皇后II(N-Queens II)
 *
 * 思路:
 * dfs
*/

class Solution {
public:
    int cnt = 0;
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
    void backtrack(vector<string>& tmp, int n, int i) {
        if (i == n) ++cnt;
        else {
            for (int j = 0; j < n; ++j) {
                if (check(tmp, i, j, n)) {
                    tmp[i][j] = 'Q';
                    backtrack(tmp, n, i + 1);
                    tmp[i][j] = '.';
                }
            }
        }
    }
    int totalNQueens(int n) {
        if (n == 1) return 1;
        if (n <= 3) return 0;

        string ori = "";
        for (int i = 0; i < n; ++i) ori.push_back('.');
        vector<string> tmp(n, ori);
        backtrack(tmp, n, 0);

        return cnt;
    }
};