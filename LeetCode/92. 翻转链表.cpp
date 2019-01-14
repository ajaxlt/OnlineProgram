#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 反转链表II(Reverse Linked List II)
 *
 * 描述:
 * 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
 *
 * 说明:
 * 1 ≤ m ≤ n ≤ 链表长度。
 *
 * 示例:
 *
 * 输入: 1->2->3->4->5->NULL, m = 2, n = 4
 * 输出: 1->4->3->2->5->NULL
 *
 * 思路:
 * 简单题
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (n == m) return head;
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;

        ListNode *p = dummy, *r = dummy, *left = dummy, *right = nullptr;
        vector<ListNode*> tmp;
        while(n--) {
            r = r -> next;
            if (m-- > 0) {
                p = p -> next;
                if(m > 0) left = left -> next;
            }
            if (m <= 0) tmp.push_back(r);
        }
        right = r -> next;

        for(int i = tmp.size() - 1; i >= 0; --i) {
            left -> next = tmp[i];
            left = left -> next;
        }
        left -> next = right;
        return dummy -> next;
    }
};