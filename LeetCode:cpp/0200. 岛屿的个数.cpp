#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 岛屿的个数(Number of Islands)
 *
 * 描述:
 * 给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量
 * 一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围
 *
 * 示例 1:
 *
 * 输入:
 * 11110
 * 11010
 * 11000
 * 00000
 *
 * 输出: 1
 *
 * 示例 2:
 *
 * 输入:
 * 11000
 * 11000
 * 00100
 * 00011
 *
 *
 * 思路:
 * dfs
*/

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '*';
        for (int g = 0; g < 4; ++g) {
            int nx = i + guide[g][0], ny = j + guide[g][1];
            if (nx >= 0 && nx < rows && ny >= 0 && ny < columns
                && grid[nx][ny] == '1') dfs(grid, nx, ny);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        if (rows == 0) return ans;
        columns = grid[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ++ans;
                }
            }
        }
        return ans;
    }
private:
    int ans = 0;
    int rows, columns;
    int guide[4][2] = {0, -1, 0, 1, 1, 0, -1, 0};
};