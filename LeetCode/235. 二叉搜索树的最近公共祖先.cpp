#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 二叉搜索树的最近公共祖先(Lowest Common Ancestor of a Binary Search Tree)
 *
 * 描述:
 * 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先
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
    TreeNode* inorder(TreeNode* root, TreeNode* p, TreeNode* q){
        if (root -> val > p -> val && root -> val < q -> val ||
            root == p || root == q) return root;
        if (root -> val < p -> val && root -> val < q -> val)
            return inorder(root -> right, p, q);
        else return inorder(root -> left, p, q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p -> val > q -> val)  return inorder(root, q, p);
        else return inorder(root, p, q);
    }
};