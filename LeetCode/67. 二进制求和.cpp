#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 二进制求和(Add Binary)
 *
 * 描述:
 * 给定两个二进制字符串，返回他们的和（用二进制表示）
 * 输入为非空字符串且只包含数字 1 和 0
 *
 * 示例:
 * 输入: a = "11", b = "1"
 * 输出: "100"
 *
 *
 * 思路:
 * 简单题
*/
class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        while(i >= 0 || j >= 0) {
            int bit1 = i >= 0 ? a[i] - '0' : 0;
            int bit2 = j >= 0 ? b[j] - '0' : 0;
            int bit = bit1 + bit2 + carry;
            carry = bit / 2;
            bit = bit % 2;
            ans = to_string(bit) + ans;
            --i, --j;
        }
        if (carry) ans = "1" + ans;
        return ans;
    }
};