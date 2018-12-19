#include <iostream>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 两数相加(Add Two Numbers)
 *
 * 描述:
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和
 *
 *
 * 示例:
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 *
 *
 * 思路:
 * 1. 此题必然需要一个哑结点 dummy 以及一个新结点l3，其中 dummy 用于备份链表表头，l3则用于遍历新链表
 * 2. 我们不能对于 nullptr 去读或写其value，因此每次遍历l3时，要保证l3不是nullptr才能 指定 l3 -> val
 * 3. 更好的方式是直接用 l3 -> next = new NodeList(val)，去定义l3的下一个结点，然后let l3 = l3 -> next
 *
*/

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* l3 = dummy;

        int carry = 0;
        while(l1 || l2) {
            int lhs = l1 ? l1 -> val : 0;
            int rhs = l2 ? l2 -> val : 0;

            int cur = lhs + rhs + carry;
            l3 -> next = new ListNode(cur % 10);
            carry = cur / 10;
            if(l1) l1 = l1 -> next;
            if(l2) l2 = l2 -> next;
            l3 = l3 -> next;
        }
        if (carry) l3 -> next = new ListNode(carry);
        return dummy -> next;
    }
};