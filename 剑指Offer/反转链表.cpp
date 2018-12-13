#include <iostream>
#include <vector>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 反转链表
 *
 * 描述: 输入一个链表，反转链表后，输出新链表的表头。
 *
 * 思路:
 * A -> B -> C
 * 如果直接 A <- B，那么 B 与 C 之间的连接会断裂
 * 因此需要一个pNext用于现将 C 保存下来
 * 此外，还需要一个pPrev保存前驱结点
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
    ListNode* ReverseList(ListNode* pHead) {
        if (!pHead || !pHead -> next) return pHead;
        ListNode* pNext = nullptr;
        ListNode* pPrev = nullptr;
        while(pHead -> next) {
            pNext = pHead -> next; //存住下一个
            pHead -> next = pPrev; //反转
            // 指针前进
            pPrev = pHead;
            pHead = pNext;
        }
        pHead -> next = pPrev; //最后一个手动
        return pHead;
    }
};