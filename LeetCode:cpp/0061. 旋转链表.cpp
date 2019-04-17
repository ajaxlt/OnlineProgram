#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 旋转链表(Rotate List)
 *
 * 描述:
 * 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
 *
 * 示例 1:
 * 输入: 1->2->3->4->5->NULL, k = 2
 * 输出: 4->5->1->2->3->NULL
 * 解释:
 * 向右旋转 1 步: 5->1->2->3->4->NULL
 * 向右旋转 2 步: 4->5->1->2->3->NULL
 *
 * 示例 2:
 * 输入: 0->1->2->NULL, k = 4
 * 输出: 2->0->1->NULL
 * 解释:
 * 向右旋转 1 步: 2->0->1->NULL
 * 向右旋转 2 步: 1->2->0->NULL
 * 向右旋转 3 步: 0->1->2->NULL
 * 向右旋转 4 步: 2->0->1->NULL
 *
 *
 * 思路:
 * 1. 第一次遍历，得到链表长度，k 对之取余
 * 2. 找到截断点，整体搬移
*/


struct ListNode {
 int val;
 ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !k) return head;
        ListNode *dummy = new ListNode(0), *p1 = head, *p2 = head;
        dummy -> next = head;
        int len = 1;
        while(head -> next){
            ++len;
            head = head -> next;
        }
        k = k % len;
        while(k--) p2 = p2 -> next;
        while(p2 -> next) {
            p1 = p1 -> next;
            p2 = p2 -> next;
        }

        p2 -> next = dummy -> next;
        dummy -> next = p1 -> next;
        p1 -> next = nullptr;

        return dummy -> next;
    }
};