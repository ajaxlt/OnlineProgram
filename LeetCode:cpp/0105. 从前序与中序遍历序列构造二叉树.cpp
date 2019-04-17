#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 从前序与中序遍历序列构造二叉树(Construct Binary Tree from Preorder and Inorder Traversal)
 *
 * 描述:
 * 根据一棵树的前序遍历与中序遍历构造二叉树
 *
 * 思路:
 * 1. 前序遍历的首结点必然是根节点
 * 2. 确定首节点在中序遍历的具体位置，二分递归处理左右子树
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,
                        int pre_beg, int pre_end, int in_beg, int in_end) {

        int root_val = preorder[pre_beg];
        TreeNode* root = new TreeNode (root_val);
        if (preorder.size() == 1) return root;

        int i = in_beg;
        for(; i <= in_end && inorder[i] != root_val; ++i);// 找到结点在中序的位置

        int l_len = i - in_beg; // 左子树长度(不包括根节点)
        int r_len = in_end - i; // 右子树长度(不包括根节点)
        if (l_len > 0) root -> left = buildTree(preorder, inorder, pre_beg + 1, pre_beg + l_len, in_beg, i - 1);

        if (r_len > 0) root -> right = buildTree(preorder, inorder, pre_beg + l_len + 1, pre_end, i + 1, in_end);


    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) return nullptr;
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};