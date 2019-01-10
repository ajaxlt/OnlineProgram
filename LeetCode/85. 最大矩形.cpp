#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 最大矩形(Maximal Rectangle)
 *
 * 描述:
 * 给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积
 *
 * 思路:
 *
 * 采用84. 的思路，对于矩阵形式，每一行向上便是一个柱形图
 * 如果当前值为0，则柱高为0，否则柱高为原柱高加1
*/

class Solution {
public:
    int largestRectangleArea(const vector<int>& heights) {
        int len = heights.size();
        if (len == 0) return 0;
        stack<int> index;
        int ans = heights[0];
        for (int i = 0; i < len + 1; ++i) {
            while(i == len || !index.empty() && heights[i] < heights[index.top()]) {
                int cur_i = index.top();
                index.pop();
                int cur_area;
                if (index.empty()) cur_area = i * heights[cur_i];
                else cur_area = (i - index.top() - 1) * heights[cur_i];
                ans = max(ans, cur_area);
                if (index.empty()) break;
            }
            index.push(i);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int rows = matrix.size(), columns = matrix[0].size();
        vector<int> heights(columns, 0);
        int ans = matrix[0][0] - '0';
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                heights[j] = matrix[i][j] == '0' ? 0 : heights[j] + 1;
            }
            ans = max(ans, largestRectangleArea(heights));
        }
        return ans;
    }
};