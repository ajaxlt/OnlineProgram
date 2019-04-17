#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 合并K个排序链表(Merge k Sorted Lists)
 *
 * 描述:
 * 合并 k 个排序链表，返回合并后的排序链表
 * 请分析和描述算法的复杂度
 *
 * 示例:
 * [
 *   1->4->5,
 *   1->3->4,
 *   2->6
 * ]
 *
 * 输出: 1->1->2->3->4->4->5->6
 *
 * 思路:
 * priority_queue
 * 自定义排序, bool operator() () {}
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct cmp {
    bool operator() (const ListNode* a, const ListNode* b) {
        return a -> val > b -> val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, cmp> Q;
        ListNode* dummy = new ListNode(0);
        ListNode* merge = dummy;
        for(auto i : lists)
            if (i != nullptr) Q.push(i);

        while(!Q.empty()) {
            ListNode* cur = Q.top();
            Q.pop();
            merge -> next = cur;
            merge = merge -> next;
            if (cur -> next) Q.push(cur -> next);
        }
        return dummy -> next;
    }
};
