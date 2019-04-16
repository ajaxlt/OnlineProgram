#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 翻转字符串里的单词(Reverse Words in a String)
 *
 * 描述:
 * 给定一个字符串，逐个翻转字符串中的每个单词
 *
 * 思路:
 * 简单题
 */

class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) return s;

        string ans = "";

        int i = 0;
        while(s[i] == ' ') ++i;
        while(i < s.size()) {
            int j = i + 1;
            while(s[j] != ' ' && j < s.size()) ++j;
            //cout << s.substr(i, j - i) << endl;
            ans = " " + s.substr(i, j - i) + ans;

            i = j;
            while(s[i] == ' ' && i < s.size()) ++i;
        }
        if (ans == "") return ans;
        else return ans.substr(1);
    }
};