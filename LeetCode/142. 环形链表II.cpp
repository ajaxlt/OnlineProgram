#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 环形链表II(Linked List Cycle II)
 *
 * 描述:
 * 给定一个链表，判断链表中是否有环，并返回环的入口
 *
 * 思路:
 * 双指针p, q: p 的速度为 1, q 的速度为 2
 * 若有环，则p，q终能相遇
 * 此时，p 不动，q 继续动，直到二次相遇，那么 q 走过的距离便是环的长度 k
 * 此时，问题退化为寻找链表的倒数第 k 个元素
 */



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return nullptr;
        bool hasCycle = false;
        ListNode *p = head, *q = head;
        while(q -> next && q -> next -> next) {
            p = p -> next;
            q = q -> next -> next;
            if (p == q) {
                hasCycle = true;
                break;
            }
        }
        if (!hasCycle) return nullptr;

        int len = 0;
        while(q != p || !len) {
            q = q -> next;
            ++len;
        }
        p = head, q = head;
        while(len--) q = q -> next;
        while(p != q) p = p -> next, q = q -> next;
        return p;
    }
};