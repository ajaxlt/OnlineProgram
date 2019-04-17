#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 删除排序链表中的重复元素II(Remove Duplicates from Sorted List II)
 *
 * 描述:
 * 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字
 *
 * 示例 1:
 * 输入: 1->2->3->3->4->4->5
 * 输出: 1->2->5
 *
 * 示例 2:
 * 输入: 1->1->1->2->3
 * 输出: 2->3
 *
 * 思路:
 * 注意，对于重复的元素，是一个都不留的
 * 因此需要多一个指针去指向前一个元素
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
        ListNode *prev = dummy, *p1 = head, *p2 = nullptr;
        while(p1) {
            if (p1 -> next && p1 -> val == p1 -> next -> val) {
                p2 = p1 -> next;
                while(p2 && p1 -> val == p2 -> val) p2 = p2 -> next;
                prev -> next = p2;
                p1 = p2;
            }
            else {
                prev = prev -> next;
                p1 = p1 -> next;
            }
        }
        return dummy -> next;
    }
};