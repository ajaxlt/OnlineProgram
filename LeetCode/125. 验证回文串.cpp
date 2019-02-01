#include <iostream>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 验证回文串(Best Time to Buy and Sell Stock III)
 *
 * 描述:
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写
 *
 * 说明：本题中，我们将空字符串定义为有效的回文串
 *
 * 示例 1:
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 *
 * 示例 2:
 * 输入: "race a car"
 * 输出: false
 *
 * 思路:
 * 简单逻辑题
 */

class Solution {
public:
    inline bool isUse(char c) {
        return c - 'A' >= 0 && 'Z' - c >= 0 ||
               c - 'a' >= 0 && 'z' - c >= 0 ||
               c - '0' >= 0 && '9' - c >= 0;
    }
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        int i = 0, j = s.size() - 1;
        while(i != j) {
            while(i < j && !isUse(s[i])) ++i;
            while(i < j && !isUse(s[j])) --j;
            if (i >= j) break;

            if (s[i] != s[j]) {
                // 如果不相等，但是
                if (s[i] - '0' >= 0 && s[i] - '9' <= 0 ||
                    s[j] - '0' >= 0 && s[j] - '9' <= 0) return false;
                else if ( s[i] - 'A' != s[j] - 'a' &&
                          s[i] - 'a' != s[j] - 'A') return false;
            }
            ++i, --j;
        }
        return true;
    }
};