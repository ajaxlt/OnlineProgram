/*
 * 来源: LeetCode
 * 题目: 矩形面积(Rectangle Area)
 *
 * 描述:
 * 见原题 https://leetcode-cn.com/problems/rectangle-area/
 *
 * 思路:
 * 两个矩形的面积之和 - 重叠部分的面积
 */

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        return (long long) (D - B) * (C - A) + (H - F) * (G - E) - (F >= D || H <= B || E >= C || G <= A ? 0 : (min(D, H) - max(B, F)) * (min(C, G) - max(A, E)));
    }
};