#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 分隔链表(Partition List)
 *
 * 描述:
 * 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前
 * 你应当保留两个分区中每个节点的初始相对位置
 *
 * 示例 1:
 * 输入: head = 1->4->3->2->5->2, x = 3
 * 输出: 1->2->2->4->3->5
 *
 * 思路:
 * 额外创建两个链表，小的给L1，大的给L2，再合并
*/

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !(head -> next)) return head;
        ListNode* dummy1 = new ListNode(0);
        ListNode* dummy2 = new ListNode(0);
        ListNode *p1 = dummy1, *p2 = dummy2;

        while(head) {
            ListNode **p3 = head -> val < x ? &p1 : &p2;
            (*p3) -> next = head;
            (*p3) = (*p3) -> next;
            head = head -> next;
        }
        p1 -> next = nullptr, p2 -> next = nullptr;
        ListNode* p = dummy2 -> next;
        while(p) {
            p1 -> next = p;
            p1 = p1 -> next;
            p = p -> next;
        }
        return dummy1 -> next;
    }
};