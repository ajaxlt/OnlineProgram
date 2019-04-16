#include <iostream>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 寻找两个有序数组的中位数(Median of Two Sorted Arrays)
 *
 * 描述:
 * 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
 * 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))
 * 你可以假设 nums1 和 nums2 不会同时为空。
 *
 *
 * 思路:
 * 问题转化为，求两个已排序数组中第 k 小的数(1 <= k < len1 + len2)
 *
 * 设数组a, b，假定 a 的长度不大于 b
 * 首先将我们都取两个数组中的第 k / 2 - 1 的元素(实际有浮动)
 * 设 a 取 ass1 个, b 取 ass2 个, 且 ass1 + ass2 = k
 *
 * 1. a[ass1 - 1] = b[ass2 - 1]， 这说明 a 的 0 ~ ass1 - 2 与 b 的 0 ~ ass2 - 2 总计 k - 2 个元素
 * 它们是前 k - 2 小元素的集合, 因此 第 k - 1 小 以及 第 k 小的元素 都是 a[ass1 - 1] 或者说是 b[ass2 - 1]
 *
 * 2. a[ass1 - 1] < b[ass2 - 1]，对于这种情况，我们可以先丢弃 a 的 0 ~ ass1 - 1 这部分，并继续求第 k - ass1 小的元素
 * 3. a[ass1 - 1] > b[ass2 - 1]，同理
 * 对于 2 和 3， 因为 ass1 + ass2 = k， 因此 k - ass1 或者 k - ass2 一定为正
 *
 * 具体操作时，我们可以用 beg1，beg2, len1, len2 去模拟丢弃的操作
 *
 *
 * 对于中位数情况
 * 1. 如果len1 + len2 = odd， 只要求第 (len1 + len2) / 2 + 1 小的元素即可
 * 2. 如果len1 + len2 = even， 只要求第 (len1 + len2) / 2 与 (len1 + len2) / 2 + 1 小的元素的平均值即可
*/

class Solution {
public:
    int findKth(vector<int>& nums1, vector<int>& nums2, int len1, int len2, int beg1, int beg2, int k) {
        //1. 确保nums1的长度不大于num2的长度
        if (len1 > len2) return findKth(nums2, nums1, len2, len1, beg2, beg1, k);
        //2. 如果len1为0，则返回nums2中第k小的数
        if (len1 == 0) return nums2[beg2 + k - 1];
        //3. 如果 k 为 1，即求最小的数
        if (k == 1) return min(nums1[beg1], nums2[beg2]);

        //每个数组分配 k / 2， 因为 num1 的长度可能不足，因此需要添加边界判断
        int ass1 = min(k / 2, len1), ass2 = k - ass1;

        if (nums1[beg1 + ass1 - 1] < nums2[beg2 + ass2 - 1])
            return findKth(nums1, nums2, len1 - ass1, len2, beg1 + ass1, beg2, k - ass1);
        else if (nums1[beg1 + ass1 - 1] > nums2[beg2 + ass2 - 1])
            return findKth(nums1, nums2, len1, len2 - ass2, beg1, beg2 + ass2, k - ass2);
        else
            return nums1[beg1 + ass1 - 1];
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size(), tot = len1 + len2;
        if (tot & 1)
            return findKth(nums1, nums2, len1, len2, 0, 0, tot / 2 + 1);
        else
            return findKth(nums1, nums2, len1, len2, 0, 0, tot / 2) / 2.0 +
                   findKth(nums1, nums2, len1, len2, 0, 0, tot / 2 + 1) / 2.0;
    }
};