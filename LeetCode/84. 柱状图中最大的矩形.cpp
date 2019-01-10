#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 柱状图中最大的矩形(Largest Rectangle in Histogram)
 *
 * 描述:
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积
 *
 * 思路:
 * **单调栈**
 * 创建一个栈，用于存储柱的“下标”,并保证栈的元素自底至顶是单调递增的
 * 1. 如果栈为空或者当前柱高度大于栈顶元素，柱的下标入栈
 * 2. 如果栈不空且当前柱高度小于栈顶元素，则开始处理栈内元素:
 *  2.1 栈顶出栈，值(下标)记为cur_i，此时处理的矩形高度为heights[cur_i]
 *  2.2 而矩形的长度: 若此时栈为空，长度为当前遍历下标；否则为当前下标 - (栈顶元素值 - 1)
 *  2.3 计算当前面积，并更新ans
 * 3. 直到当前遍历柱高度大于栈顶元素，柱的下标继续入栈，即返回步骤1
 *
 * 4. 最后需要判断边界。即，当元素全部遍历完，而栈仍然不空值，需要对栈进行一个额外的循环处理
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        if (len == 0) return 0;

        stack<int> index;
        int ans = heights[0];
        heights.push_back(-1);
        for (int i = 0; i < len + 1; ++i) {
            while(!index.empty() && heights[i] < heights[index.top()]) {
                int cur_i = index.top();
                index.pop();
                int cur_area = heights[cur_i] * (index.empty() ? i : i - index.top() - 1);
                ans = max(ans, cur_area);
            }
            index.push(i);
        }
        return ans;
    }
};