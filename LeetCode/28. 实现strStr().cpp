#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 实现strStr()(Implement strStr())
 *
 * 描述:
 * 实现 strStr() 函数
 * 给定一个 haystack 字符串和一个 needle 字符串
 * 在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)
 * 如果不存在，则返回  -1
 *
 * 思路:
 * 简单题
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        if (needle.size() > haystack.size()) return -1;

        int i = 0, j = 0;
        for (; i < haystack.length(); ++i) {
            if (j == needle.size()) return i - needle.size();
            if (haystack[i] == needle[j]) ++j;
            else {
                i -= j; // 回退
                j = 0;
            }
        }
        if (j == needle.size()) return i - needle.size();
        else return -1;
    }
};