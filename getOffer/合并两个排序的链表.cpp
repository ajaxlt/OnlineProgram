#include <iostream>
#include <vector>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 合并两个排序的链表
 *
 * 描述: 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
 *
 * 思路:
 * 常规题，利用哑结点
 *
*/
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* pDummy = new ListNode(0);
        ListNode* pNew = pDummy;
        while(pHead1 || pHead2) {
            int val1 = pHead1 ? pHead1 -> val : INT32_MAX;
            int val2 = pHead2 ? pHead2 -> val : INT32_MAX;
            if (val1 < val2){
                pNew -> next = pHead1;
                pHead1 = pHead1 -> next;
            } else {
                pNew -> next = pHead2;
                pHead2 = pHead2 -> next;
            }
            pNew = pNew -> next;
        }
        return pDummy -> next;
    }
};