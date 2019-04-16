#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 有序链表转换二叉搜索树(Convert Sorted List to Binary Search Tree)
 *
 * 描述:
 * 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1
 *
 * 思路:
 * 1. 由于链表是单向的，不同于数组，这里采用的是左闭右开的区间处理方式
 * 2. 利用二倍速指针找到链表的中点，也就是根结点
 */

/**
 * Definition for singly-linked list.
 **/
struct ListNode {
      int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head, ListNode* tail) {
        // 采用左闭右开的区间处理法则, 二倍速指针法找到中点值
        if (head == tail) return nullptr;
        ListNode *p = head, *q = head;
        while(q != tail && q -> next != tail) {
            p = p -> next;
            q = q -> next -> next;
        }
        TreeNode* root = new TreeNode(p -> val);
        root -> left = sortedListToBST(head, p);
        root -> right = sortedListToBST(p -> next, tail);

        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        return sortedListToBST(head, nullptr);
    }
};