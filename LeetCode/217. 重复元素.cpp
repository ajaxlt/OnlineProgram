#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 存在重复元素(Contains Duplicate)
 *
 * 描述:
 * 给定一个整数数组，判断是否存在重复元素
 * 如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false
 *
 * 思路:
 * set判重
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> mySet;
        for (auto i : nums) {
            if (mySet.count(i)) return true;
            else mySet.insert(i);
        }
        return false;
    }
};