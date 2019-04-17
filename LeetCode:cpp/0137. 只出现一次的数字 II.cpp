#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 只出现一次的数字II(Single Number II)
 *
 * 描述:
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素
 *
 * 说明：
 * 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 *
 * 示例 1:
 * 输入: [2,2,3,2]
 * 输出: 3
 *
 * 示例 2:
 * 输入: [0,1,0,1,0,1,99]
 * 输出: 99
 *
 * 思路:
 * 基于逻辑电路，设计一个模3加的运算
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (int n : nums) {
            b = ~a & (b ^ n);
            a = ~b & (a ^ n);
        }
        return b;
    }
};