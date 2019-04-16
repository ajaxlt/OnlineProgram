#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 反转链表(Reverse Linked List)
 *
 * 描述:
 * 反转一个单链表
 *
 * 思路:
 * 末尾结点的后一个置空
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;


        stack<ListNode*> tmp;
        while(head) {
            tmp.push(head);
            head = head -> next;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;

        while(!tmp.empty()) {
            p -> next = tmp.top();
            p = p -> next;
            cout << p -> val << endl;
            tmp.pop();
        }
        p -> next = nullptr;
        return dummy -> next;
    }
};