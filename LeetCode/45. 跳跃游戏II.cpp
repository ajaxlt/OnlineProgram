#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 跳跃游戏II(Jump Game II)
 *
 * 描述:
 * 给定一个非负整数数组，你最初位于数组的第一个位置
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度
 * 你的目标是使用最少的跳跃次数到达数组的最后一个位置
 *
 * 示例:
 * 输入: [2,3,1,1,4]
 * 输出: 2
 * 解释: 跳到最后一个位置的最小跳跃数是 2
 * 从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置
 *
 * 思路:
 * bfs
*/
struct node{
    int idx, stp; // idx -> 下标， stp -> 步数
    friend bool operator < (node a, node b) {
        return a.stp == b.stp ? a.idx <= b.idx : a.stp > b.stp;
        // stp 第一顺位，小的优先; idx 第二顺位， 大的优先
    }
};
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) return 0;
        const int len = nums.size();
        bool use[len];
        memset(use, false, sizeof(use));
        priority_queue<node> Q;
        node beg = {0, 0};
        Q.push(beg);
        while(!Q.empty()) {
            node cur = Q.top();
            for (int i = 1; i <= nums[cur.idx]; ++i) {
                if (cur.idx + i == len - 1) return ++cur.stp;
                if (!use[cur.idx + i]) {
                    Q.push(node{cur.idx + i, cur.stp + 1});
                    use[cur.idx + i] = true;
                }
            }
            Q.pop();
        }
        return -1;
    }
};