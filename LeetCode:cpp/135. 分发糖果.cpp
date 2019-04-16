#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 分发糖果(Candy)
 *
 * 描述:
 * 老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分
 * 你需要按照以下要求，帮助老师给这些孩子分发糖果：
 *
 * 每个孩子至少分配到 1 个糖果
 * 相邻的孩子中，评分高的孩子必须获得更多的糖果
 * 那么这样下来，老师至少需要准备多少颗糖果呢？
 *
 * 示例 1:
 * 输入: [1,0,2]
 * 输出: 5
 * 解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果
 *
 * 示例 2:
 * 输入: [1,2,2]
 * 输出: 4
 * 解释: 你可以分别给这三个孩子分发 1、2、1 颗糖果
 * 第三个孩子只得到 1 颗糖果，这已满足上述两个条件
 *
 * 思路:
 * 左 -> 右, 右 -> 左
 */

class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        int ans = len;

        vector<int> tmp(len);

        for (int i = 0; i < len - 1; ++i) {
            if (ratings[i + 1] > ratings[i]) {
                tmp[i + 1] = tmp[i] + 1;
                ans += tmp[i + 1];
            }
        }
        for (int i = len - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1] && tmp[i] <= tmp[i + 1]) {
                ans += tmp[i + 1] + 1 - tmp[i];
                tmp[i] = tmp[i + 1] + 1;
            }
        }
        return ans;
    }
};