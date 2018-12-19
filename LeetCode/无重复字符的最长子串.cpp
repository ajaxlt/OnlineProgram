#include <iostream>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 无重复字符的最长子串(Longest Substring Without Repeating Characters)
 *
 * 描述:
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度
 *
 *
 * 思路:
 * 一次遍历
 * 1. 需要一个辅助备忘录, 用于存储出现过的字符，并标记其下标，可以用普通数组或者map
 * 2. 需要一个指针来标记当前最长字符的左端点
 * 3.1 如果当前字符没有出现, 则当前最长长度为 i - left + 1
 * 3.2 如果当前自出已经出现，则找到前一个出现位置的下一个，且将该下标置于 left
 * 3.3 无论是否出现，必将更新 map
 *
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        const int len = 256;
        int left = 0, rlt = -1, m[len];
        for (int i = 0; i < len; ++i) m[i] = -1;
        for (int i = 0; i < s.length(); ++i) {
            if (m[s[i]] != -1 && m[s[i]] >= left) left = m[s[i]] + 1;
            rlt = max(rlt, i - left + 1);
            m[s[i]] = i;
        }
        return rlt;
    }
};