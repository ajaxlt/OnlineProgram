#include <iostream>
#include <string>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 最长回文子串(Longest Palindromic Substring)
 *
 * 描述:
 * 给定一个字符串 s，找到 s 中最长的回文子串
 * 你可以假设 s 的最大长度为 1000
 *
 * 示例 1：
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 *
 * 示例 2：
 * 输入: "cbbd"
 * 输出: "bb"
 *
 *
 * 思路:
 * 中心扩展法
 * 1. 外层遍历整个字符串
 * 2. 针对与每个字符，以奇偶情况，分别进行中心扩展
*/

class Solution {
public:
    void match(string s, int beg, int end, int cnt){
        int head = -1;
        while (beg >= 0 && end < s.length()) {
            if (s[beg] == s[end]) {
                head = beg;
                --beg, ++end;
                cnt += 2;
            }
            else break;
        }
        if (head != -1 && cnt > maxLen) {
            maxLen = cnt;
            res = s.substr(head, cnt);
        }
    }
    string longestPalindrome(string s) {
        int len = s.length();
        if (len == 0 || len == 1) return s;

        for (int i = 0; i < len - 1; ++i) {
            //1. odd
            match(s, i, i, -1);
            //2. even
            match(s, i, i + 1, 0);
        }
        return res;
    }
private:
    string res = "";
    int maxLen = -1;
};