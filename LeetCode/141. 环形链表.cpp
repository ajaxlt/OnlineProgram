#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 环形链表(Linked List Cycle)
 *
 * 描述:
 * 给定一个链表，判断链表中是否有环
 *
 * 思路:
 * 双指针，速度差
 */



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode *p = head, *q = head;
        while(q -> next && q -> next -> next) {
            p = p -> next;
            q = q -> next -> next;
            if (p == q) return true;
        }
        return false;
    }
};