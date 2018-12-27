#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 与所有单词相关联的字串(Implement strStr())
 *
 * 描述:
 * 给定一个字符串 s 和一些长度相同的单词 words。在 s 中找出可以恰好串联 words 中所有单词的子串的起始位置
 * 注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序
 *
 * 示例:
 * s = "barfoothefoobarman",
 * words = ["foo","bar"]
 *
 * 输出: [0, 9]
 *
 * 解释: 从索引 0 和 9 开始的子串分别是 "barfoor" 和 "foobar"
 * 输出的顺序不重要, [9,0] 也是有效答案

 * 思路:
 * 首先，建立一个map以存储words，键为str，值为cnt
 * 遍历 s， 以 s 的每个字符为头
 * 再建立一个map， 与前一个map对照
 * 扫描 s, 走的规定长度内如果恰好能够用尽给定的 words, 便是有效的
*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (words.empty() || s.size() < words.size() * words[0].length()) return {};
        if (s.empty()) {
            if (words[0].empty()) return {0};
            else return {};
        }

        vector<int> rlt;
        unordered_map<string, int> m1;
        int totlen = s.size(); // 主串的长度
        int cnt = words.size(); // 总共的字串数
        int len = words[0].size();// 每个子串的长度
        for(auto i : words) ++m1[i];
        for (int beg = 0; beg <= totlen - cnt * len; ++beg) { // 主串的每个字符试做头
            unordered_map<string, int> m2;
            //开始逐个单词匹配
            int j = 0;
            for (; j < cnt; ++j) {
                string tmp = s.substr(beg + j * len, len);
                if (m1.find(tmp) == m1.end() || m1[tmp] == m2[tmp]) break;
                ++m2[tmp];
            }
            if (j == cnt) rlt.push_back(beg);
        }
        return rlt;
    }
};