#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 单词拆分II(Word Break II)
 *
 * 描述:
 * 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict
 * 在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中
 * 返回所有这些可能的句子
 *
 * 思路:
 * 先利用 动态规划 判断是否可以被拆分
 * 然后利用 dfs 枚举所有情况
 */

class Solution {
public:
    void dfs(string s, const vector<string>& wordDict, int i, string tmp) {
        if (i == s.size()) ans.push_back(tmp.substr(0, tmp.size() - 1));
        else if (i < s.size()) {
            for (string word : wordDict) {
                int len = word.size();
                if (s.substr(i, len) == word) dfs(s, wordDict, i + len, tmp + word + " ");
            }
        }
    }
    bool can(string s, vector<string>& wordDict) {
        int len = s.size();
        vector<bool> dp(len + 1, false);

        set<string> mySet(wordDict.begin(), wordDict.end());
        dp[0] = true;

        for (int i = 1; i <= len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && mySet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len];
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (can(s, wordDict))
            dfs(s, wordDict, 0, "");
        return ans;
    }
private:
    vector<string> ans;
};
