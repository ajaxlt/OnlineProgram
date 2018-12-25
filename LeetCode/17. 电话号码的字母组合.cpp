#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 电话号码的字母组合(Letter Combinations of a Phone Number)
 *
 * 描述:
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母
 *
 * 详见原题
 *
 * 思路:
 * 回溯法
 *
*/
class Solution {
public:
    void dfs(vector<string>& rlt, string tmp, string dig, int i, map<char, string> mymap) {
        if (i == dig.length()) rlt.push_back(tmp);
        else{
            for(int j = 0; j < mymap[dig[i]].length(); ++j) {
                tmp += mymap[dig[i]].substr(j, 1);
                dfs(rlt, tmp, dig, i + 1, mymap);
                tmp = tmp.substr(0, tmp.length() - 1);
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> rlt;
        if (digits == "") return rlt;
        map<char,string> mymap;
        mymap['2'] = "abc";
        mymap['3'] = "def";
        mymap['4'] = "ghi";
        mymap['5'] = "jkl";
        mymap['6'] = "mno";
        mymap['7'] = "pqrs";
        mymap['8'] = "tuv";
        mymap['9'] = "wxyz";
        dfs(rlt, "", digits, 0, mymap);
        return rlt;
    }
};