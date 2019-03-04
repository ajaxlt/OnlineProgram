#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 最大间距(Maximum Gap)
 *
 * 描述:
 * 给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值
 * 如果数组元素个数小于 2，则返回 0。
 *
 * 示例 1:
 * 输入: [3,6,9,1]
 * 输出: 3
 * 解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3
 *
 * 示例 2:
 * 输入: [10]
 * 输出: 0
 * 解释: 数组元素个数小于 2，因此返回 0
 *
 * 说明:
 * 你可以假设数组中所有元素都是非负整数，且数值在 32 位有符号整数范围内
 * 请尝试在线性时间复杂度和空间复杂度的条件下解决此问题
 *
 * 思路:
 * 桶排序
 *
 * 假设数组的长度为N，准备 N + 1 个桶，把 max 放在第 N + 1 号桶
 * 每个桶的区间大小为 (max - min) / N
 *
 * 每个数组元素n 应该放在 (n - min) * len / (max - min) 中
 * 桶有三个属性，桶的最小值，最大值以及桶是否空
 * 遍历每个非空桶，计算前一个桶的最小值和后一个桶的最大值之差
 */

struct bucket {
    bool empty = true;
    int Min = INT32_MAX;
    int Max = INT32_MIN;
};
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return 0;
        int Min = INT32_MAX, Max = INT32_MIN;

        // 找到数组中的最大值和最小值
        for (int n : nums) {
            Min = min(Min, n);
            Max = max(Max, n);
        }
        if (Min == Max) return 0;

        vector<bucket> b(len + 1);
        for (int n : nums) {
            // 注意溢出
            long tmp = (long) (n - Min) * (long) len;
            int i = tmp / (Max - Min); // 所属桶的编号
            b[i].Min = b[i].empty ? n : min(b[i].Min, n);
            b[i].Max = b[i].empty ? n : max(b[i].Max, n);
            b[i].empty = false;
        }
        int ans = 0, pre = b[0].Max; // 因为存在最小值，因此 0 号桶必不空
        for (int i = 1; i <= len; ++i) {
            if (!b[i].empty) {
                ans = max(ans, b[i].Min - pre);
                pre = b[i].Max;
            }
        }
        return ans;
    }
};
