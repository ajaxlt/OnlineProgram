#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 最大数(Largest Number)
 *
 * 描述:
 * 给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数
 *
 * 示例 1:
 * 输入: [10,2]
 * 输出: 210
 *
 * 示例 2:
 * 输入: [3,30,34,5,9]
 * 输出: 9534330
 *
 * 思路:
 * 1. 自定义比较函数
 * 2. 注意带 "0" 的输入
*/

bool cmp(int& a, int& b) {
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        for (auto n : nums) {
            if (n == 0 && ans == "")
                continue;
            ans += to_string(n);
        }
        return ans == "" ? "0" : ans;
    }
private:
    string ans = "";
};