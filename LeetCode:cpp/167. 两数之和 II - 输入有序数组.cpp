#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 两数之和 II - 输入有序数组(Two Sum II - Input array is sorted)
 *
 * 描述:
 * 给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数
 * 函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2
 *
 * 思路:
 * 双指针
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        int i = 0, j = len - 1;
        while(i < j) {
            if (numbers[i] + numbers[j] == target) return {i + 1, j + 1};
            else if (numbers[i] + numbers[j] < target) ++i;
            else --j;
        }
        return {};
    }
};