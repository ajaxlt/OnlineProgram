#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 两个链表的第一个公共节点
 *
 * 描述:
 * 输入两个链表，找出它们的第一个公共结点
 *
 * 思路:
 * 1. 找出两者的长度差 delta
 * 2. 长者先行 delta 步，进行同步
 * 3. 遍历至尾即可
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
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        if (!pHead1 || !pHead2) return nullptr;
        ListNode *p1 = pHead1, *p2 = pHead2;
        int delta = 0;
        while(p1 -> next || p2 -> next) {
            if (!(p1 -> next)) {
                ++delta;
                p2 = p2 -> next;
            }
            else if(!(p2 -> next)) {
                --delta;
                p1 = p1 -> next;
            }
            else {
                p1 = p1 -> next;
                p2 = p2 -> next;
            }
        }
        p1 = pHead1, p2 = pHead2;
        if (delta > 0) {
            for (int i = 0; i < delta; ++i) p2 = p2 -> next;
        }
        else {
            for (int i = 0; i < -delta; ++i) p1 = p1 -> next;
        }
        while(p1 && p2) {
            if (p1 == p2) return p1;
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        return nullptr;
    }
};