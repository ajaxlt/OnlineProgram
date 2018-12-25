#include <iostream>
#include <map>
#include <stack>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 合并两个有序链表(Merge Two Sorted Lists)
 *
 * 描述:
 * 将两个有序链表合并为一个新的有序链表并返回
 * 新链表是通过拼接给定的两个链表的所有节点组成的。
 *
 * 思路:
 * 简单题，注意边界处理
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* merge = dummy;

        while(l1 || l2) {
            int cur1 = l1 ? l1 -> val : INT32_MAX;
            int cur2 = l2 ? l2 -> val : INT32_MAX;
            if (cur1 < cur2) {
                merge -> next = l1;
                l1 = l1 -> next;
            } else {
                merge -> next = l2;
                l2 = l2 -> next;
            }
            merge = merge -> next;
        }
        return dummy -> next;
    }
};