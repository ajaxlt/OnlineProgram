#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 单词接龙(Word Ladder)
 *
 * 描述:
 * 给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出从 beginWord 到 endWord 的最短转换序列
 * 转换需遵循如下规则：
 *
 * 每次转换只能改变一个字母, 转换过程中的中间单词必须是字典中的单词
 *
 * 说明:
 * 如果不存在这样的转换序列，返回一个空列表
 * 所有单词具有相同的长度
 * 所有单词只由小写字母组成
 * 字典中不存在重复的单词
 * 你可以假设 beginWord 和 endWord 是非空的，且二者不相同
 *
 *
 * 示例 1:
 * 输入:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 *
 * 输出: 5
 * 解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5
 *
 * 示例 2:
 *
 * 输入:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 输出: 0
 * 解释: endWord "cog" 不在字典中，所以无法进行转换
 *
 * 思路:
 * 简单宽搜
 */
struct MyNode{
    int step;
    string name;
    MyNode(int _step, string _name): step(_step), name(_name) {}
    friend bool operator <(MyNode a, MyNode b) {
        return a.step > b.step;
    }
};
class Solution {
public:
    int diff(string a, string b){
        int cnt = 0;
        for (int i = 0; i < a.size(); ++i)
            if (a[i] != b[i]) ++cnt;
        return cnt;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<bool> vis(wordList.size(), false);
        priority_queue<MyNode> Q;
        Q.push({1, beginWord});
        while(!Q.empty()) {
            MyNode cur = Q.top();
            Q.pop();
            for (int i = 0; i < wordList.size(); ++i) {
                if (!vis[i] && diff(cur.name, wordList[i]) == 1) {
                    if (wordList[i] == endWord) return cur.step + 1;
                    Q.push({cur.step + 1, wordList[i]});
                    vis[i] = true;
                }
            }
        }
        return 0;
    }
};