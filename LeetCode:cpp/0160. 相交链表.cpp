#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 相交链表(Intersection of Two Linked Lists)
 *
 * 描述:
 * 编写一个程序，找到两个单链表相交的起始节点
 *
 * 思路:
 * 一个如果走到头，就去回去另一个的头，以抹平距离差
 * 最后两个指针都分别走过A 和 B
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        ListNode *p = headA, *q = headB;
        while(p != q){
            p = p ? p -> next : headB;
            q = q ? q -> next : headA;
        }
        return p;
    }
};