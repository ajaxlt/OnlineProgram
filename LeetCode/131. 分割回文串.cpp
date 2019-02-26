#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 分割回文串(Palindrome Partitioning)
 *
 * 描述:
 * 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
 * 返回 s 所有可能的分割方案。
 *
 * 示例:
 * 输入: "aab"
 * 输出:
 * [
 *  ["aa","b"],
 *  ["a","a","b"]
 * ]
 *
 * 思路:
 * 回溯法
 */

class Solution {
public:
    bool check(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j) if (s[i++] != s[j--]) return false;
        return true;
    }
    void backtrack(string s, vector<string>& tmp, int end) {
        if (end == s.size()) ans.push_back(tmp);
        for (int i = end; i < s.size(); ++i) {
            string cur = s.substr(end, i - end + 1);
            if (check(cur)) {
                tmp.push_back(cur);
                backtrack(s, tmp, i + 1);
                tmp.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<string> tmp;
        backtrack(s, tmp, 0);
        return ans;
    }
private:
    vector<vector<string>> ans;
};