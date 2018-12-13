#include <iostream>
#include <string.h>
#include <string>
#include <stack>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 翻转单词顺序列
 *
 * 描述:
 * “student. a am I” -> "I am a student."
 *
 * 思路:
 * 简单题
 *
*/
class Solution {
public:
    string ReverseSentence(string str) {
        if (str.empty()) return str;
        str.push_back(' ');
        stack<string> tmp;
        string rlt = "";
        const int len = str.size();
        int i = 0, j = 0;
        while(j != len) {
            if (str[j] == ' ') {
                tmp.push(str.substr(i, j - i));
                i = j + 1;
            }
            ++j;
        }
        while(!tmp.empty()) {
            rlt += tmp.top();
            tmp.pop();
            if (!tmp.empty()) rlt.push_back(' ');
        }
        return rlt;
    }
};
