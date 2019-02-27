#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 克隆图(Clone Graph)
 *
 * 描述:
 * 给定无向连通图中一个节点的引用，返回该图的深拷贝（克隆）
 * 图中的每个节点都包含它的值 val（Int） 和其邻居的列表（list[Node]）
 *
 * 思路:
 * map + bfs
 */

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> m; //key -> old, value -> new

        Node* tmp = new Node(node -> val, {}); // 先复制头结点

        m[node] = tmp;

        queue<Node*> Q;
        Q.push(node);

        while(!Q.empty()) {
            Node* cur = Q.front();
            for (auto n : cur -> neighbors) {
                if (!m.count(n)) { // 如果结点 n 没有访问，则复制它，并将它推入队列
                    m[n] = new Node(n -> val, {});
                    Q.push(n);
                }
                (m[cur] -> neighbors).push_back(m[n]); // 建立关系
            }
            Q.pop();
        }
        return tmp;
    }
};