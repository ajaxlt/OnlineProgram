#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 删除排序链表中的重复元素II(Remove Duplicates from Sorted List II)
 *
 * 描述:
 * 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。
 * 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
 *
 * 示例 1:
 * 给定 nums = [1,1,1,2,2,3]
 * 函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3
 * 你不需要考虑数组中超出新长度后面的元素
 *
 * 思路:
 * 简单题
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int i = 1, j = 1, cnt = 1, prev = nums[0];
        for (; j < nums.size(); ++j) {
            if (nums[j] == prev) ++cnt;
            else {
                cnt = 1;
                prev = nums[j];
            }
            nums[i++] = nums[j];
            if (cnt == 2) {
                cnt = 0;
                while(j + 1 < nums.size() && nums[j + 1] == prev) ++j;
                if (j + 1 < nums.size()) prev = nums[j + 1];
            }
        }
        return i;
    }
};