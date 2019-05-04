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
 * 先整体翻转，然后对单词逐一翻转
*/
class Solution {
public:
    void reverseHelper(string& str, int beg, int end) {
        while(beg < end) swap(str[beg++], str[end--]);
    }
    string ReverseSentence(string str) {
        reverseHelper(str, 0, str.size() - 1);
        int i = 0;
        while(i < str.size()) {
            int j = i;
            while(j < str.size() && str[j] != ' ') ++j;
            reverseHelper(str, i, j - 1);
            i = j + 1;
        }
        return str;
    }
};
