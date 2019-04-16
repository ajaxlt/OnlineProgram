#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 只出现一次的数字(Single Number)
 *
 * 描述:
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 *
 * 思路:
 * 异或
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (auto i : nums) ans ^= i;
        return ans;
    }
};