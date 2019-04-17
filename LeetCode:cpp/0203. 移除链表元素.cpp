#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 移除链表元素(Remove Linked List Elements)
 *
 * 描述:
 * 删除链表中等于给定值 val 的所有节点
 *
 * 示例:
 * 输入: 1->2->6->3->4->5->6, val = 6
 * 输出: 1->2->3->4->5
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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;

        ListNode* prev = dummy;
        while(head) {
            if (head -> val == val) prev -> next = head -> next;
            else prev = head;
            head = head -> next;
        }
        return dummy -> next;
    }
};