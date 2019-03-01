#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 二叉树的后序遍历(Binary Tree Postorder Traversal)
 *
 * 描述:
 * 给定一个二叉树，返回它的 后序 遍历
 *
 * 思路:
 * 树遍历，循环方式的模板
 * 左 - 右 - 根。
 * 可以先 根 - 右 - 左, 然后逆序输出即可
 */



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return ans;

        stack<TreeNode*> stk;

        while(root || !stk.empty()) {
            if (root) {
                ans.push_back(root -> val);
                stk.push(root -> left);

                root = root -> right;
            } else {
                root = stk.top();
                stk.pop();
            }
        }
        vector<int> tmp(ans.rbegin(), ans.rend());
        return tmp;
    }
private:
    vector<int> ans;
};