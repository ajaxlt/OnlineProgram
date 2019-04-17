#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 平衡二叉树(Balanced Binary Tree)
 *
 * 描述:
 * 给定一个二叉树，判断它是否是高度平衡的二叉树
 * 本题中，一棵高度平衡二叉树定义为：
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1
 *
 * 思路:
 * 记叶子结点的高度为 0, root 的高度为 1 + max(左高，右高)
 * 由于函数返回值是布尔，则高度需要用 指针 或 引用的方式 在形参中返回
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root, int& len) {
        if (!root) return true;
        int llen = 0, rlen = 0;
        if (isBalanced(root -> left, llen) &&
            isBalanced(root -> right, rlen) &&
            abs(llen - rlen) <= 1)
        {
            len = 1 + max(llen, rlen);
            return true;
        }
        else return false;

    }
    bool isBalanced(TreeNode* root) {
        int len = 0;
        return isBalanced(root, len);
    }
};