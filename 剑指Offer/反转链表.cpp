#include <iostream>
#include <string.h>
#include <string>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 反转链表
 *
 * 思路:
 * 1. 头插法
 * 2. 箭头反向
*/

//1. 头插法，每次把下一个结点放到头部
class Solution1 {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == nullptr || pHead->next == nullptr) return pHead;
        ListNode* dummy = new ListNode(0);
        dummy->next = pHead;
        while(pHead->next != nullptr) {
            ListNode* next = pHead->next;
            ListNode* nnext = next->next;
            ListNode* head = dummy->next;
            next->next = head;
            dummy->next = next;
            pHead->next = nnext;
        }
        return dummy->next;
    }
};
//2. 箭头反向
class Solution2 {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == nullptr || pHead->next == nullptr) return pHead;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while(pHead->next != nullptr) {
            next = pHead->next;
            pHead->next = prev;
            
            prev = pHead;
            pHead = next;
        }
        pHead->next = prev;
        return pHead;
    }
};
