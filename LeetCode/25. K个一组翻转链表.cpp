#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: K个一组翻转链表(Reverse Nodes in K-Group)
 *
 * 描述:
 * 给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表
 * k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序
 *
 * 示例:
 * 给定这个链表：1->2->3->4->5
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 *
 * 思路:
 * 注意处理时要限定两头
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1) return head;

        ListNode* dummy = new ListNode(0);
        ListNode* newHead = dummy;
        newHead -> next = head;

        while(newHead -> next) {
            tmp.clear();
            ListNode* iter = newHead -> next;
            for(int i = 0; i < k; ++i) {
                if (!iter) return dummy -> next;
                tmp.push_back(iter);
                iter = iter -> next;
            }
            ListNode* r = iter;
            for(int i = k - 1; i >= 0; --i) {
                newHead -> next = tmp[i];
                newHead = newHead -> next;
            }
            newHead -> next = r;
        }
        return dummy -> next;
    }
private:
    vector<ListNode*> tmp;
};