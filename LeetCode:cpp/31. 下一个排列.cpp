#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 下一个排列(Next Permutation)
 *
 * 描述:
 * 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）
 * 必须原地修改，只允许使用额外常数空间
 *
 * 示例:
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 *
 * 思路:
 * 1. 对于一个排列，其后部某一部分已经达到了最大排列，即降序。我们找到它，并标记为 i ~ end
 * 2. 下一个全排列: i - 1 位置，“增大一格”, 并将 i ~ end 按降序排序
 *
 * 因此，算法步骤为:
 * 1. 从右往左，找到降序起点，标记为 i(如果 i = 0， 则原排列为降序，直接翻转即可)
 * 2. 从 i ~ end 中，找到其中最小的，恰好大于 i - 1 的元素标记为 j
 * 3. 交换 i - 1 和 j
 * 4. 翻转 i ~ end
*/
class Solution {
public:
    inline void rev(vector<int>& nums, int beg, int end) {
        for(; beg < end; ++beg, --end) swap(nums[beg], nums[end]);
    }
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) return;
        if (nums.size() == 2) {
            swap(nums[0], nums[1]);
            return;
        }
        int i = nums.size() - 1, j;
        for(; i >= 0 && nums[i] <= nums[i - 1]; --i);
        if (i == 0) {
            rev(nums, 0, nums.size() - 1);
            return;
        }
        for(j = i; j < nums.size() && nums[j] > nums[i - 1]; ++j);
        swap(nums[i - 1], nums[j - 1]);
        rev(nums, i, nums.size() - 1);
    }
};