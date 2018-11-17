#include <iostream>
#include <vector>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 删除链表中重复的结点
 *
 * 描述: 在一个排序的链表中，删除重复的结点
 * 1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5 修改为
 * 1 -> 2 -> 5
 *
 * 思路: 注意分析逻辑，只要是重复的，一个都不要
*/
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (pHead == nullptr) return pHead;

        ListNode* dummy = new ListNode(0); // 哑结点
        dummy -> next = pHead;
        ListNode* newHead = dummy; //头
        ListNode* cur = newHead -> next;
        while(cur) {
            if (cur -> next == nullptr){
                newHead -> next = cur;
                return dummy -> next;
            }
            else if(cur -> val != cur -> next -> val) {
                newHead -> next = cur;
                newHead = cur;
                cur = cur -> next;
            }
            else {
                while(cur -> next && cur -> val == cur -> next -> val) cur = cur -> next;
                if (cur -> next == nullptr) {
                    newHead -> next = nullptr;
                    return dummy -> next;
                }
                else cur = cur -> next;
            }
        }
        return dummy -> next;
    }
};