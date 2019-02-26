#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 最长连续序列(Longest Consecutive Sequence)
 *
 * 描述:
 * 给定一个未排序的整数数组，找出最长连续序列的长度
 * 要求算法的时间复杂度为 O(n)
 *
 * 示例:
 * 输入: [100, 4, 200, 1, 3, 2]
 * 输出: 4
 * 解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4
 *
 *
 * 思路:
 * 中心插值
 * 1. 先轮询当前值的相邻左右是否存在，若存在，则记录左右的可扩展长度
 * 2. 新长度为 1 + 左扩展 + 右扩展
 * 3. 更新最大连续长度
 * 4. 更新当前值的连续长度，以及左右端点的连续长度
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> M;
        int ans = 0;
        for (int num : nums) {
            if (!M.count(num)) {
                int lower = M.count(num - 1) ? M[num - 1] : 0; // 左区间可扩展长度
                int upper = M.count(num + 1) ? M[num + 1] : 0; // 右区间可扩展长度
                int len = 1 + lower + upper;
                //cout << num << " " << len << endl;
                ans = max(ans, len); // 更新目标值
                M[num] = len; //
                if (M.count(num - lower)) M[num - lower] = len; // 更新左端点的连续长度
                if (M.count(num + upper)) M[num + upper] = len; // 更新右端点的连续长度
            }
        }
        return ans;
    }
};