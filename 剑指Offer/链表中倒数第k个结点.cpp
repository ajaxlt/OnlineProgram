#include <iostream>
#include <vector>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 链表中的倒数第k个结点
 *
 * 描述: 输入一个链表，输出该链表中倒数第k个结点。
 *
 * 思路:
 * 双指针法，2号指针先走 k 步即可
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (!pListHead || k == 0) return nullptr;
        ListNode* i = pListHead;
        ListNode* j = pListHead;
        for (int t = 1; t < k; ++t) {
            if (!(i -> next)) return nullptr;
            i = i -> next;
        }
        while(i -> next) {
            i = i -> next;
            j = j -> next;
        }
        return j;
    }
};