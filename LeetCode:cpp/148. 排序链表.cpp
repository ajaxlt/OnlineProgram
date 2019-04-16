#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 排序链表(Sort List)
 *
 * 描述:
 * 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序
 *
 * 思路:
 * 链表的快速排序
 */



struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* partition(ListNode* p, ListNode* r) {
        int x = r -> val;

        ListNode* part = new ListNode(0);
        part -> next = p;
        ListNode* beg = p;
        while(beg != r) {
            if (beg -> val <= x) {
                swap(beg -> val, part -> next -> val);
                part = part -> next;
            }
            beg = beg -> next;
        }
        swap(r -> val, part -> next -> val);

        return part;
    }

    void quickSort(ListNode* p, ListNode* r) {
        if (p != r && r -> next != p) {
            ListNode* q = partition(p, r);
            quickSort(p, q);
            quickSort(q -> next -> next,  r);
        }
    }
    ListNode* sortList(ListNode* head) {
        if (!head) return head;

        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* p = head;
        ListNode* r = head;

        while(r -> next) r = r -> next;
        quickSort(p, r);
        return dummy -> next;
    }
};