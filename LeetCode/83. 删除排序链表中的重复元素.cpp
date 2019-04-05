#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 删除排序链表中的重复元素II(Remove Duplicates from Sorted List)
 *
 * 描述:
 * 删除排序链表中的重复元素
 *
 * 示例 1:
 * 输入: 1->1->2
 * 输出: 1->2
 *
 * 示例 2:
 * 输入: 1->1->2->3->3
 * 输出: 1->2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *p1 = head, *p2 = nullptr;
        while(p1) {
            if (p1 -> next && p1 -> val == p1 -> next -> val) {
                p2 = p1 -> next;
                while(p2 && p1 -> val == p2 -> val) p2 = p2 -> next;
                p1 -> next = p2;
            }
            else p1 = p1 -> next;
        }
        return dummy -> next;
    }
};