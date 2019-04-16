#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 二叉搜索树中第K小的元素(Kth Smallest Element in a BST)
 *
 * 描述:
 * 给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素
 *
 * 思路:
 * 简单题
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void inorder(TreeNode* root, int k) {
        if (!root) return;
        inorder(root -> left, k);
        if (++cnt == k) {
            tar = root -> val;
            return;
        }
        inorder(root -> right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return tar;

    }
private:
    int cnt = 0;
    int tar = 0;
};