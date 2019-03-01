#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 重排链表(Reorder List)
 *
 * 描述:
 * 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
 * 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换
 *
 * 思路:
 * 利用快慢指针找到中点
 * 将后半部分的链表反转再插入到前半部分即可
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        while(head -> next) {
            next = head -> next;
            head -> next = prev;

            prev = head;
            head = next;
        }
        head -> next = prev;
        return head;
    }
    void reorderList(ListNode* head) {
        if (!head || !(head -> next) || !(head -> next -> next)) return;
        // 快慢指针找终点
        ListNode* p = head;
        ListNode* q = head;
        while(q -> next && q -> next -> next) {
            p = p -> next;
            q = q -> next -> next;
        }


        q = reverse(p -> next);
        p = head;
        while (q) {
            ListNode* pNext = p -> next;
            ListNode* qNext = q -> next;
            p -> next = q;
            q -> next = pNext;
            p = pNext;
            q = qNext;
        }
        p -> next = nullptr;
    }
};
