#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 求众数(Majority Element)
 *
 * 描述:
 * 给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素
 * 你可以假设数组是非空的，并且给定的数组总是存在众数
 *
 * 思路:
 * 令第一个数为目标，计数为 1
 * 遍历数组，如果当前数与目标相同，则 计数 +1
 * 如果不同，则计数 -1，若计数等于0，则重新设置目标为当前元素，且置计数为1
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int tar = nums[0];
        int cnt = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == tar) ++cnt;
            else {
                --cnt;
                if (!cnt) {
                    tar = nums[i];
                    cnt = 1;
                }
            }
        }
        return tar;
    }
};