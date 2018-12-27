#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 两两交换链表中的节点(Swap Nodes in Pairs)
 *
 * 描述:
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表
 *
 * 示例:
 * 给定 1->2->3->4, 你应该返回 2->1->4->3
 *
 * 思路:
 * 简单题
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* newHead = dummy;
        newHead -> next = head;

        while(newHead -> next) {
            ListNode* p = newHead -> next;
            ListNode* q = p -> next;
            if (!q) return dummy -> next;
            ListNode* r = q -> next;
            newHead -> next = q;
            q -> next = p;
            p -> next = r;
            newHead = p;
        }
        return dummy -> next;
    }
};
