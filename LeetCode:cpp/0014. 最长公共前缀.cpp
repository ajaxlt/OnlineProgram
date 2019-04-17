#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 最长公共前缀(Longest Common Prefix)
 *
 * 描述:
 * 编写一个函数来查找字符串数组中的最长公共前缀
 * 如果不存在公共前缀，返回空字符串 ""
 *
 * 思路:
 * 简单题
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int i = 0;
        bool flag = true;
        while(flag) {
            char cur = ' ';
            for (auto s : strs) {
                if (i > s.length() || (cur != ' ' && cur != s[i])) {
                    flag = false;
                    break;
                }
                if (cur == ' ') cur = s[i];
            }
            if (flag) ++i;
        }
        return strs[0].substr(0, i);
    }
};