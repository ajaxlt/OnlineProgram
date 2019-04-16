/*
 * 来源: LeetCode
 * 题目: 完全二叉树的节点个数(Count Complete Tree Nodes)
 *
 * 描述:
 * 给出一个完全二叉树，求出该树的节点个数
 *
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int countNodes(TreeNode* root) {
        return root == nullptr ? 0 : 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};