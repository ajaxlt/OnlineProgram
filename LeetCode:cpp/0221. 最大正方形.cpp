/*
 * 来源: LeetCode
 * 题目: 最大正方形(Maximal Square)
 *
 * 描述:
 * 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积
 *
 * 示例:
 *
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 *
 * 输出: 4
 *
 * 思路:
 * 动态规划
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        //dp[i][j] -> 以 i, j 为右下角的最大正方形边长
        //if matrix[i][j] = 0, dp[i][j] = 0
        //else dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
        int rows = matrix.size();
        if (rows == 0) return 0;
        int cols = matrix[0].size();
        if (cols == 0) return 0;

        vector<vector<int> > dp(rows, vector<int>(cols, 0));
        dp[0][0] = matrix[0][0] - '0';
        int ans = dp[0][0];
        for (int i = 1; i < rows; ++i) { dp[i][0] = matrix[i][0] - '0'; ans = max(ans, dp[i][0]);}
        for (int j = 1; j < cols; ++j) { dp[0][j] = matrix[0][j] - '0'; ans = max(ans, dp[0][j]);}
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    int lo = min(dp[i - 1][j], dp[i][j - 1]);
                    lo = min(lo, dp[i - 1][j - 1]);
                    dp[i][j] = 1 + lo;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans * ans;
    }
};