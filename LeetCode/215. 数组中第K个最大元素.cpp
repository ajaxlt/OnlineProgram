#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 数组中的第K个最大元素(Kth Largest Element in an Array)
 *
 * 描述:
 * 在未排序的数组中找到第 k 个最大的元素
 *
 * 思路:
 * 快速排序
 */

class Solution {
public:
    int partition(vector<int>& nums, int p, int r) {
        int i = p;
        for (int j = p; j < r; ++j) {
            if (nums[j] > nums[r]) swap(nums[j], nums[i++]);
        }
        swap(nums[r], nums[i]);
        return i;
    }
    int findKthLargest(vector<int>& nums, int k, int p, int r) {
        if (p < r) {
            int q = partition(nums, p, r);
            if (q - p + 1 == k) return nums[p + k - 1];
            else if (q - p + 1 < k) return findKthLargest(nums, k - q + p - 1, q + 1, r);
            else return findKthLargest(nums, k, p, q - 1);
        }
        return nums[p];
    }
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, k, 0, nums.size() - 1);
    }
};