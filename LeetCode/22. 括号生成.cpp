#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 括号生成(Generate Parentheses)
 *
 * 描述:
 * 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合
 *
 * 示例:
 * 给出 n = 3，生成结果为：
 * [
 *  "((()))",
 *  "(()())",
 *  "(())()",
 *  "()(())",
 *  "()()()"
 * ]
 *
 * 思路:
 * 回溯法
*/

class Solution {
public:
    void dfs(vector<string>& tmp, string s, int i, int j, int n) {
        if (i == n && j == n) tmp.push_back(s);
        else {
            if (i != n) dfs(tmp, s + "(", i + 1, j, n);
            if (j < i) dfs(tmp, s + ")", i, j + 1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> tmp;
        dfs(tmp, "", 0, 0, n);
        return tmp;
    }
};