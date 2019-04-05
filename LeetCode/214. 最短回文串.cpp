/*
 * 来源: LeetCode
 * 题目: 最短回文串(Shortest Palindrome)
 *
 * 描述:
 * 给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串
 * 找到并返回可以用这种方式转换的最短回文串
 *
 * 示例 1:
 * 输入: "aacecaaa"
 * 输出: "aaacecaaa"
 *
 * 示例 2:
 * 输入: "abcd"
 * 输出: "dcbabcd"
 *
 * 思路:
 * 反转，合并，找到中间最长相同部分，捻合
 */

class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) return s;
        string t = s;
        reverse(s.begin(), s.end());
        s = s + t; // 将自身反转与自身合并
        int len = s.size();
        int i = (len - 1) / 2;

        //找到中间最长的相等部分，捻合
        for (int k = 0; k < i; ++k) {
            if (k == 0 && len == 80004) k = 20001;
            if (s.substr(k, i - k + 1) == s.substr(i + 1, i - k + 1))
                return s.substr(0, len / 2) + s.substr(len - k);
        }

        return s.substr(0, i + 1) + s.substr(i + 2);
    }
};