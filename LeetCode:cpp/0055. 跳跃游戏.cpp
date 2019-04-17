#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 跳跃游戏(Jump Game)
 *
 * 描述:
 * 给定一个非负整数数组，你最初位于数组的第一个位置
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度
 * 判断你是否能够到达最后一个位置
 *
 * 示例 1:
 * 输入: [2,3,1,1,4]
 * 输出: true
 * 解释: 从位置 0 到 1 跳 1 步, 然后跳 3 步到达最后一个位置。
 *
 * 思路:
 * 贪心，只关心能不能到，不关心步数
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) return true;
        // 贪心算法
        // 我们只关心当前能够达到的最遥远位置
        int longest = 0;
        for (int i = 0; i <= longest && i < nums.size(); ++i) {
            longest = max(longest, nums[i] + i);
        }
        return longest >= nums.size() - 1;
    }
};