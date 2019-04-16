#include <iostream>
#include <map>
#include <string>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 罗马数字转整数(Roman to Integer)
 *
 * 描述:
 * 转换法则同 12.
 *
 * 思路:
 * 打表匹配
*/
class Solution {
public:
    int romanToInt(string s) {
        map<string, int>R2I;
        R2I["I"] = 1;
        R2I["V"] = 5;
        R2I["X"] = 10;
        R2I["L"] = 50;
        R2I["C"] = 100;
        R2I["D"] = 500;
        R2I["M"] = 1000;
        R2I["IV"] = 4;
        R2I["IX"] = 9;
        R2I["XL"] = 40;
        R2I["XC"] = 90;
        R2I["CD"] = 400;
        R2I["CM"] = 900;
        int rlt = 0, i = 0;
        while(i < s.length()) {
            if (R2I.count(s.substr(i, 2))) {
                rlt += R2I[s.substr(i, 2)];
                i += 2;
                continue;
            }
            if (R2I.count(s.substr(i, 1))) {
                rlt += R2I[s.substr(i, 1)];
                i += 1;
            }
            else return -1;
        }
        return rlt;
    }
};