#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 对链表进行插入排序(Insertion Sort List)
 *
 * 描述:
 * -
 *
 * 思路:
 * 插排基本思路
 */



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !(head -> next)) return head;

        ListNode* dummy = new ListNode(0);
        ListNode* p = head;
        dummy -> next = head;

        while(p -> next) {
            ListNode* cur = p -> next;
            if (cur -> val > p -> val) {
                p = p -> next;
                continue;
            }

            ListNode* nn = p -> next -> next;
            ListNode* q = dummy;
            while(q != p) {
                if (cur -> val <= q -> next -> val) {
                    ListNode* tmp = q -> next;
                    q -> next = cur;
                    cur -> next = tmp;
                    break;
                }
                q = q -> next;
            }
            p -> next = nn;
        }
        return dummy -> next;
    }
};