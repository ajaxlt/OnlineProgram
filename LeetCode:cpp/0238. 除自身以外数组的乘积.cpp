#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 除自身以外数组的乘积(Delete Node in a Linked List)
 *
 * 描述:
 * 给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积
 *
 * 思路:
 * 左一次，右一次
 */


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int base = 1;
        vector<int> ans(nums.size());

        for(int i = 0; i < nums.size(); ++i) {
            ans[i] = base;
            base *= nums[i];
        }
        base = 1;
        for (int j = nums.size() - 1; j >= 0; --j) {
            ans[j] *= base;
            base *= nums[j];
        }
        return ans;
    }
};