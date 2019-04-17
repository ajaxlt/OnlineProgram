#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 有效数字(Valid Number)
 *
 * 描述:
 * 验证给定的字符串是否可以解释为十进制数字
 *
*/
class Solution {
public:
    bool isNumber(string s) {
        if (s == "") return false;
        int i = 0, j = s.size() - 1;
        while(s[i] == ' ' && i < s.size()) ++i;
        if (i == s.size()) return false;
        while(s[j] == ' ' && j >= 0) --j;
        regex r("[\\+-]?(\\d+\\.?|\\.\\d+)\\d*(e[\\+-]?\\d+)?");
        return regex_match(s.substr(i, j - i + 1), r);
    }
};