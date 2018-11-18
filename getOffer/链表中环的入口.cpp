#include <iostream>
#include <vector>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 链表中环的入口节点
 *
 * 描述: 给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null
 *
 * 思路:
 * 与找倒数第 k 个结点的思路类似，还是双指针法
 * 如果链表内有环，则调整两个指针的速度，则两者必相遇
 * 因此
 * 1. i 指针的速度为1，j 指针的速度为2，视两者是否会相遇
 * 2. 若相遇，此时，继续移动j, 其必定经过 k 步重新回到 i 的位置, k便是环的长度
 * 3. 重新让i, j 指向头结点，让 j 先行 k 步，然后i, j 同行，首次相遇点便是所求
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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if (!pHead) return nullptr;
        ListNode* i = pHead; //慢指针
        ListNode* j = pHead; //快指针

        bool flag = false; //是否有环?
        while(j -> next && j -> next -> next) {
            j = j -> next -> next;
            i = i -> next;
            if (i == j) {
                flag = true;
                break;
            }
        }
        if (!flag) return nullptr; // 无环，结束

        int len = 1; // 环的长度
        while(j -> next != i) {
            j = j -> next;
            ++len;
        }
        i = pHead, j = pHead; // 重新从头开始
        for(int k = 0; k < len; ++k) j = j -> next;
        while(i != j) {
            i = i -> next;
            j = j -> next;
        }
        return i;
    }
};