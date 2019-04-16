#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 单词接龙II(Word Ladder II)
 *
 * 描述:
 * 给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord 的最短转换序列
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
 * 示例 1:
 * 输入:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 *
 * 输出:
 * [
 *  ["hit","hot","dot","dog","cog"],
 *  ["hit","hot","lot","log","cog"]
 *  ]
 *
 * 示例 2:
 * 输入:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 *
 * 输出: []
 * 解释: endWord "cog" 不在字典中，所以不存在符合要求的转换序列。
 *
 * 思路:
 * 参考 https://blog.csdn.net/qq_29996285/article/details/86696301
 */
struct MyNode{
    // 结点结构体，包含:
    // 1. 结点名(单词名)
    // 2. 前驱下标(根据wordList)
    // 3. 当前步数(以endWord为起点)
    string name;
    int prev;
    int step;
    MyNode(string _name, int _prev, int _step) :
            name(_name), prev(_prev), step(_step) {}
};
class Solution {
public:
    // 判断两个单词的距离(不同单词个数)是否为1
    bool diff(const string& lhs, const string& rhs) {
        int cnt = 0;
        for (int i = 0; i < lhs.size(); ++i) {
            if (lhs[i] != rhs[i] && (++cnt) > 1) return false;
        }
        return cnt;
    }
    // 生成邻接图
    void generate_graph(string &beginWord, vector<string>& wordList,
                        map<string, vector<string>>& adj) {
        bool hasBegin = false; // 判断起点是否在 单词表 内
        for (string i : wordList) {
            if (i == beginWord) {
                hasBegin = true;
            }
            adj[i] = {}; // 初始化每个结点的邻接图
        }
        for (int i = 0; i < wordList.size(); ++i) {
            for (int j = i + 1; j < wordList.size(); ++j) {
                if (diff(wordList[i], wordList[j])) {
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
            // 如果单词表内不含beginWord, 则需要在邻接图中额外加入beginWord
            if (!hasBegin && diff(beginWord, wordList[i]))
                adj[beginWord].push_back(wordList[i]);
        }
    }
    void bfs(string& beginWord, string& endWord,
             map<string, vector<string>>& adj,
             vector<MyNode>& Q, vector<int>& endWordPos) {
        // 这里的 Q 是用 vector 模拟的 queue
        map<string, int> vis; // 记录结点是否被访问过

        int min_step = 0; // 记录到达endWord的最小步数

        Q.push_back(MyNode(beginWord, -1, 1)); // 起点 beginWord 的前驱为 -1

        vis[beginWord] = 1;

        int front = 0; // 判断终止

        while(front != Q.size()) {
            string cur_node = Q[front].name;

            int step = Q[front].step; // 当前步长

            // 当 step > min_step 时, 说明所有最短路径已经被排查
            if (min_step != 0 && step > min_step) break;

            // 当 cur_node == endWord，说明找到了一条合理的路径
            // 需要将此时 cur_node 也就是 endWord 在 队列Q 中的下标记录下来
            if (cur_node == endWord) {
                min_step = step;
                endWordPos.push_back(front);
            }

            vector<string> cur_neighbors = adj[cur_node];
            // 获取当前结点的所有邻接结点
            for (string n : cur_neighbors) {
                // 如果该 邻接结点 还未被访问
                // 或者该 邻接结点 已经被访问，但是与当前路径长度相等 ...
                // bfs中，后面的路径不可能比前面的短，至多相等，即 vis[n] = step + 1
                if (vis.count(n) == 0 || vis[n] == step + 1) {
                    Q.push_back(MyNode(n, front, step + 1));

                    vis[n] = step + 1;
                }
            }
            ++front;
        }

    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        map<string, vector<string>> adj; // 邻接图
        generate_graph(beginWord, wordList, adj); // 生成邻接图, 填充 adj
        vector<MyNode> Q; // 用 vector 模拟 queue
        vector<int> endWordPos; // 该 vector 记录了各路径中，endWord 处于 Q 中的下标位置
        bfs(beginWord, endWord, adj, Q, endWordPos); // 填充 endWordPos

        for (int i = 0; i < endWordPos.size(); ++i) {
            int pos = endWordPos[i];
            vector<string> path;
            // 这里，打印路径是一个逆序的过程
            // 先从终点 endWord 开始，往前寻找他的前驱
            while(pos != -1) {
                path.push_back(Q[pos].name);
                pos = Q[pos].prev;
            }
            ans.push_back({});

            // 将路径逆转
            for (int j = path.size() - 1; j >= 0; --j) ans[i].push_back(path[j]);
        }
        return ans;
    }
private:
    vector<vector<string>> ans;;
};