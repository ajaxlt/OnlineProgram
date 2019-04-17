#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 二叉树的前序遍历(Binary Tree Preorder Traversal)
 *
 * 描述:
 * 给定一个二叉树，返回它的 前序 遍历
 *
 * 思路:
 * 树遍历，循环方式的模板
 * 每次先遍历左子结点，利用栈存入右子结点
 */



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return ans;

        stack<TreeNode*> stk;

        while(root || !stk.empty()) {
            if (root) {
                ans.push_back(root -> val);
                stk.push(root -> right);
                root = root -> left;
            } else {
                root = stk.top();
                stk.pop();
            }
        }
        return ans;
    }
private:
    vector<int> ans;
};