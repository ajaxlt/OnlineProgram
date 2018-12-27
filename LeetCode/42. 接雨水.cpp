#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 接雨水(Trapping Rain Water)
 *
 * 描述:
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水
 * 详见原题
 *
 * 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出: 6
 *
 * 思路:
 * 2次遍历
*/
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        const int len = height.size();
        int ans = 0, i = 0, cnt = 0, left = i;
        // ans -> 最终结果, i -> 当前槽, left -> 左围栏
        while(++i < len) {
            if (height[i] >= height[left]) {
                // 右围栏找到
                ans += (i - left - 1) * height[left] - cnt;
                left = i;
                cnt = 0;
            }
            else  cnt += height[i];
        }
        // 现在的 left 应该是最高的
        i = len - 1;
        int right = i;
        cnt = 0;
        while(--i >= left) {
            if (height[i] >= height[right]) {
                // 左围栏找到
                ans += (right - i - 1) * height[right] - cnt;
                right = i;
                cnt = 0;
            }
            else cnt += height[i];
        }
        return ans;
    }
};