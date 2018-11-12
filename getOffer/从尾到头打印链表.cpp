#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 从尾到头打印链表
 *
 * 描述: 输入一个链表，按链表值从尾到头的顺序返回一个ArrayList
 *
 * 思路:
 * 先进后出，利用递归或者栈实现即可
 * 不过，当链表非常长的时候，递归可能导致函数调用栈溢出，因此用栈更鲁邦一些
 */

struct ListNode {
    int val; struct ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> rlt;
        stack<ListNode*> tmp;
        while(head) {
            tmp.push(head);
            head = head -> next;
        }
        while(!tmp.empty()) {
            rlt.push_back(tmp.top() -> val);
            tmp.pop();
        }
        return rlt;
    }
};