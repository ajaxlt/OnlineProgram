#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 颜色分类(Sort Colors)
 *
 * 描述:
 * 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列
 * 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
 *
 * 示例:
 * 输入: [2,0,2,1,1,0]
 * 输出: [0,0,1,1,2,2]
 *
 * 思路:
 * 双指针
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = nums.size() - 1, k = 0;
        while(k <= j) {
            if (nums[k] == 0) swap(nums[k], nums[i++]);
            else if (nums[k] == 2) {
                swap(nums[k], nums[j--]);
                continue;
            }
            ++k;
        }
    }
};