#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 二叉树的中序遍历(Binary Tree Inorder Traversal)
 *
 * 描述:
 * 给定一个二叉树，返回它的 中序 遍历
 *
 * 用循环法
 *
 * 思路:
 * 栈
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;

        while(root || !stk.empty()) {
            if (root) {
                stk.push(root);
                root = root -> left;
            }
            else {
                TreeNode* fa = stk.top();
                stk.pop();
                ans.push_back(fa -> val);
                root = fa -> right;
            }
        }
        return ans;
    }
};