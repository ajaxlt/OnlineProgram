#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 从中序与后序遍历序列构造二叉树(Construct Binary Tree from Inorder and Postorder Traversal)
 *
 * 描述:
 * 根据一棵树的中序遍历与后序遍历构造二叉树
 *
 * 思路:
 * 与 105 题类似, 后序遍历的尾结点一定是根结点
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int in_beg, int in_end, int post_beg, int post_end) {
        int root_val = postorder[post_end];
        TreeNode *root = new TreeNode(root_val);

        if (postorder.size() == 1) return root;

        int i = in_beg;
        for(; i <= in_end && inorder[i] != root_val; ++i);

        int l_len = i - in_beg;
        int r_len = in_end - i;

        if (l_len > 0) root -> left = buildTree(inorder, postorder, in_beg, i - 1, post_beg, post_beg + l_len - 1);
        if (r_len > 0) root -> right = buildTree(inorder, postorder, i + 1, in_end, post_beg + l_len, post_end - 1);

        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty()) return nullptr;
        return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};