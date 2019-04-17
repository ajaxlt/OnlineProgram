#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 分割数组(Partition Array into Disjoint Intervals)
 *
 * 描述:
 * 给定一个数组 A，将其划分为两个不相交（没有公共元素）的连续子数组 Left 和 right， 使得：
 * Left 中的每个元素都小于或等于 right 中的每个元素
 * Left 和 right 都是非空的
 * Left 要尽可能小
 * 在完成这样的分组后返回 Left 的长度。可以保证存在这样的划分方法
 * 
 * 示例 1：
 * 输入：[5,0,3,8,6]
 * 输出：3
 * 解释：Left = [5,0,3]，right = [8,6]
 * 
 * 示例 2：
 * 输入：[1,1,1,0,6,12]
 * 输出：4
 * 解释：Left = [1,1,1,0]，right = [6,12]
 *
 * 思路:
 * 维护两个变量，左边最大值 maxOfLeft 和 全局最大值 maxOfAll
 * 均初始化为 A[0], 从 index = 1 开始遍历一遍数组
 *
 * 每次更新 全局最大值 maxOfAll
 * 1. 如果 左边最大值 maxOfLeft <= A[i], 很好不需要处理
 * 2. 如果 左边最大值 maxOfLeft > A[i], 说明发现了一个比左边最大要小的，那么我们必须把他包含进来了
 * 因此 分割下标 p 变为了 i, 且此时左边最大值与全局最大值一致，更新
 */

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int maxOfLeft = A[0], maxOfAll = A[0], p = 0;

        for (int i = 1; i < A.size(); ++i) {
            maxOfAll = max(maxOfAll, A[i]);
            if (maxOfLeft > A[i]) {
                maxOfLeft = maxOfAll;
                p = i;
            }
        }
        return p + 1;
    }
};