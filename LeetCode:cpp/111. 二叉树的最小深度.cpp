#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 二叉树的最小深度(Minimum Depth of Binary Tree)
 *
 * 描述:
 * 给定一个二叉树，找出其最小深度
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量
 *
 * 思路:
 * 无左时找右，无右时找左
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        else if (!(root -> left)) return 1 + minDepth(root -> right);
        else if (!(root -> right)) return 1 + minDepth(root -> left);
        else return 1 + min(minDepth(root -> left), minDepth(root -> right));
    }
};