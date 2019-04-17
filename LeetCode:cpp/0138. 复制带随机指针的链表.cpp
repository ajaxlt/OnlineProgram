#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 复制带随机指针的链表(Copy List with Random Pointer)
 *
 * 描述:
 * 给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
 * 要求返回这个链表的深拷贝。
 *
 * 说明：
 * 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 *
 * 思路:
 * 利用map，两次遍历
 * 第一次，不管random指针，但要在map中关联旧结点和新结点
 * 第二次，复制random指针
 */

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        map<Node*, Node*> m;

        Node* dummy = new Node();
        Node* tmp = head;
        Node* cpy = new Node(head -> val, nullptr, nullptr);
        dummy -> next = cpy;

        m[tmp] = cpy;
        while(tmp -> next) {
            tmp = tmp -> next;
            cpy -> next = new Node(tmp -> val, nullptr, nullptr);
            cpy = cpy -> next;
            m[tmp] = cpy;
        }
        tmp = head;
        while(tmp) {
            m[tmp] -> random = m[tmp -> random];
            tmp = tmp -> next;
        }
        return dummy -> next;
    }
};