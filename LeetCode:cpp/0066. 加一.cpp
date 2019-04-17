#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 加一(Plus One)
 *
 * 描述:
 * 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一
 * 最高位数字存放在数组的首位， 数组中每个元素只存储一个数字
 * 你可以假设除了整数 0 之外，这个整数不会以零开头
 *
 * 示例:
 * 输入: [1,2,3]
 * 输出: [1,2,4]
 * 解释: 输入数组表示数字 123
 *
 *
 * 思路:
 * 简单题
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        for (int i = digits.size() - 1; i >= 0; --i) {
            int cur = digits[i] + carry;
            if (i == digits.size() - 1) ++cur;
            carry = cur / 10;
            digits[i] = cur % 10;
            if (carry == 0) break;
        }
        if (carry > 0) {
            vector<int> ans(digits.size() + 1, 0);
            ans[0] = 1;
            return ans;
        }
        return digits;
    }
};