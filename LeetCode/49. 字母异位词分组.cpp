#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 字母异位词分组(Group Anagrams)
 *
 * 描述:
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串
 *
 * 示例:
 *
 * 输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * 输出:
 * [
 *  ["ate","eat","tea"],
 *  ["nat","tan"],
 *  ["bat"]
 * ]
 *
 * 说明：
 * 所有输入均为小写字母
 * 不考虑答案输出的顺序
 *
 * 思路:
 * 给字母异位词配置相同的键
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int len = 'z' - 'a' + 1;
        unordered_map<string, vector<string>> myMap;
        for (string s : strs) {
            vector<int> cnt(len, 0);
            string tmp = "";
            for(char c : s) ++cnt[c - 'a'];
            for(int i : cnt) tmp += to_string(i) + "/";
            //cout<< tmp << endl;
            myMap[tmp].push_back(s);
        }

        for(auto m : myMap) ans.push_back(m.second);
        return ans;
    }
};