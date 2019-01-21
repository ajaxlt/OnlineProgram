#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 反转字符串(Reverse String)
 *
 * 描述:
 * 编写一个函数，其作用是将输入的字符串反转过来
 */

class Solution {
public:
    string reverseString(string s) {
        string tmp = "";
        for (int i = s.size() - 1; i >= 0; --i)
            tmp.push_back(s[i]);
        return tmp;
    }
};