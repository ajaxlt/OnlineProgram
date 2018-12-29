#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 插入区间(Insert Interval)
 *
 * 描述:
 * 给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度
 * 如果不存在最后一个单词，请返回 0
 * 说明：一个单词是指由字母组成，但不包含任何空格的字符串。
 *
 * 示例:
 * 输入: "Hello World"
 * 输出: 5
 *
 * 思路:
 * 简单题
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        int t = s.length() - 1;
        for (; t >= 0 && s[t] == ' '; --t);
        if (t == -1) return 0;
        int h = t;
        for(; h >= 0 && s[h] != ' '; --h);
        return t - h;
    }
};