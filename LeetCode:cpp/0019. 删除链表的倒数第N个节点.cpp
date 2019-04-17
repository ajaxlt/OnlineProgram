#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 删除链表的倒数第N个结点(Remove Nth Node From End of List)
 *
 * 描述:
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 *
 * 示例:
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 *
 * 思路:
 * 1. 对于"倒数"，使用双指针可以解决
 * 2. 为了避免对于头结点的讨论，需要引入一个哑结点
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* p = dummy;
        ListNode* q = dummy;
        while(n--) q = q -> next;
        while(q -> next) {
            p = p -> next;
            q = q -> next;
        }
        p -> next = p -> next -> next;
        return dummy -> next;;
    }
};