#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 盛水最多的容器(Container With Most Water)
 *
 * 描述:
 * 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai)
 * 在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)
 * 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水
 *
 * 即 给定一数组，在其中选择两个点，使得围成的矩形面积最大(高由其中较小的那个决定)
 *
 * 思路:
 * 双指针法
 *
 * 首先在数组的首末安插两个指针i, j，计算当前面积A
 * 接下来，我们有两种选择，移动i或是移动j
 * 如果说，i 是较小的那个
 * 那么当前矩形的高就是i
 *
 * 1. 我们移动 i，此时，矩形的底将减少，但高却有可能增大，因此面积有可能变大
 * 2. 我们移动 j，此时，矩形的底将减少，而因为高受限于i，故高只有可能减少，因此面积不会变大
 *
 * 综上，我们总应该去移动较小的那个指针，这样才"有可能"获取更大的面积
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int head = 0, tail = height.size() - 1;
        while(head != tail) {
            if (height[head] < height[tail]) {
                area = max((tail - head) * height[head], area);
                head++;
            }
            else {
                area = max((tail - head) * height[tail], area);
                tail--;
            }
        }
        return area;
    }
private:
    int area = 0;
};