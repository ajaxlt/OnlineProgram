#include <iostream>
#include <vector>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 礼物的最大价值
 *
 * 描述:
 * 在一个m * n 的棋盘的每一格中都放有一个礼物，每个礼物都有一定的价值(>0)
 * 从棋盘的左上角开始拿格子里的礼物，并每次向右或向下移动一格，直到到达棋盘的右下角
 * 求那道礼物价值的最大值？
 *
*/
/*      解法1. 2维dp      */
class Solution1 {
public:
    // dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + gift[i][j];
    // dp[0][0] = gift[0][0]
    int maxValue(const vector<vector<int>>& gift) {
        int rows = gift.size(), columns = gift[0].size();
        vector<vector<int>> dp(rows, vector<int>(columns, 0));
        for (int i = 0; i < gift.size(); ++i) {
            for (int j = 0; j < gift[i].size(); ++j) {
                int v1 = i - 1 >= 0 ? dp[i - 1][j] : 0;
                int v2 = j - 1 >= 0 ? dp[i][j - 1] : 0;
                dp[i][j] = max(v1, v2) + gift[i][j];
            }
        }
        return dp[rows - 1][columns - 1];
    }
};

/*      解法2. 1维dp      */
class Solution2 {
public:
    // 对于 i, j 而言, 只与i - 1, j 和 i, j - 1有关

    // 对于 j = 0 而言，我们只需考虑 i - 1, j 即可，我们直接用 i, j 覆盖 i - 1,
    // 对于 j != 0 而言，(i, j - 1) 刚生成, (i - 1, j) 还保留着, 因此我们直接能用, 算出较大者覆盖即可
    int maxValue(const vector<vector<int>>& gift) {
        int rows = gift.size(), columns = gift[0].size();
        vector<int> dp(columns - 1, 0);
        for (int i = 0; i < gift.size(); ++i) {
            for (int j = 0; j < gift[i].size(); ++j) {
                int v1 = i - 1 >= 0 ? dp[j] : 0;
                int v2 = j - 1 >= 0 ? dp[j - 1]: 0;
                dp[j] = max(v1, v2) + gift[i][j];
            }
        }
        return dp[columns - 1];
    }
};
int main() {
    Solution2 s;
    vector<vector<int>> gift = {{1,10,3,8},{12,2,9,6},{5,7,4,11},{3,7,16,5}};
    cout << s.maxValue(gift) << endl;
}