#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 二叉树的最大深度(Maximum Depth of Binary Tree)
 *
 * 描述:
 * 给定一个二叉树，找出其最大深度
 *
 * 思路:
 * 简单递归
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return !root ? 0 : 1 + max(maxDepth(root -> left), maxDepth(root -> right));
    }
};