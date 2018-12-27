#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 报数(Count and Say)
 *
 * 描述:
 * 报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 *
 * 1 被读作  "one 1"  ("一个一") , 即 11
 * 11 被读作 "two 1s" ("两个一"）, 即 21
 * 21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211
 * 给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项
 *
 * 注意：整数顺序将表示为一个字符串
 *
 * 思路:
 * 简单找规律
*/
class Solution {
public:
    const int Max = 30;
    string countAndSay(int n) {
        string rlt[Max + 1];
        rlt[1] = "1";
        if (n == 1) return rlt[1];
        for (int i = 2; i <= n; ++i) {
            rlt[i] = "";
            char cur = rlt[i - 1][0];
            int cnt = 1;
            for (int j = 1; j < rlt[i - 1].length(); ++j) {
                if (rlt[i - 1][j] == cur) ++cnt;
                else {
                    rlt[i] += to_string(cnt);
                    rlt[i].push_back(cur);
                    cur = rlt[i - 1][j];
                    cnt = 1;
                }
            }
            rlt[i] += to_string(cnt);
            rlt[i].push_back(cur);
        }
        return rlt[n];
    }
};