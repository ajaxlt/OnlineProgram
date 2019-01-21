#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 反转字符串中的单词 III(Reverse Words in a String III)
 *
 * 描述:
 * 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序
 *
 * 示例:
 * 输入: "Let's take LeetCode contest"
 * 输出: "s'teL ekat edoCteeL tsetnoc"
 */

class Solution {
public:
    string reverseWords(string s) {
        s.push_back(' ');
        string ans = "";
        string tmp = "";
        int i = 0;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == ' ') {
                for (int k = j - 1; k >= i; --k) tmp.push_back(s[k]);
                ans += tmp;
                if (j != s.size() - 1) ans.push_back(' ');
                tmp = "";
                i = j + 1;
            }
        }
        return ans;
    }
};