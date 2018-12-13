#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 两数之和(Two Sum)
 *
 * 描述:
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组**下标**
 * 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素
 *
 * 思路:
 * 如果仅需要输出数，可以用set;
 * 输出下标，那么只能用map
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> myMap;
        for(int i = 0; i < nums.size(); ++i) {
            int tar2 = target - nums[i];
            if (myMap.count(tar2)) return {myMap[tar2], i};
            myMap[nums[i]] = i;
        }
    }
};