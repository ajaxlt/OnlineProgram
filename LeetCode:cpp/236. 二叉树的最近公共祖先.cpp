#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 二叉树的最近公共祖先(Lowest Common Ancestor of a Binary Tree)
 *
 * 描述:
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先
 *
 * 思路:
 * 分治。
 *
 * 边界: 如果 root 空，或 root = p，或 root = q， 返回 root
 * 从左右子树继续向下查找..
 * 如果左右返回都是空，则说明找不到，返回空
 * 如果左右有一个是空的，返回不空的
 * 如果左右都不空，返回根
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);

        if (!left && !right) return nullptr;
        else if(!left || !right) return left ? left : right;
        else return root;
    }
};