#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 格雷编码(Gray Code)
 *
 * 描述:
 * 格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异
 * 给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。格雷编码序列必须以 0 开头
 *
 * 思路:
 * 对于一个二进制数 i, 其格雷码为 i ^ (i >> 1)
 */


class Solution {
public:
    vector<int> grayCode(int n) {
        int len = 1 << n;
        vector<int> ans(len);
        for (int i = 0; i < len; ++i) ans[i] = i ^ (i >> 1);
        return ans;
    }
};