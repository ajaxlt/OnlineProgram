#include <iostream>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 杨辉三角II(Pascal's Triangle II)
 *
 * 描述:
 * 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行
 *
 * 示例:
 * 输入: 3
 * 输出: [1,3,3,1]
 *
 * 思路:
 * 简单题
 *
 */

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> tmp(rowIndex + 1, 1);

        for (int i = 0; i <= rowIndex; ++i) {
            int prev = 1;
            for (int j = 1; j <= i / 2; ++j) {
                int prev2 = prev;
                prev = tmp[j];
                tmp[j] = prev2 + tmp[j];
                tmp[i - j] = tmp[j];
            }
        }
        return tmp;
    }
};