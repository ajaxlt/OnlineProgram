#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 二叉树的层次遍历 II(Binary Tree Level Order Traversal II)
 *
 * 描述:
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 *
    3
   / \
  9  20
    /  \
   15   7
   返回其自底向上的层次遍历为：
[
  [15,7],
  [9,20],
  [3]
]
 *
 * 思路:
 * 利用 vector 的 insert 进行头插
 */
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            vector<int> tmp;
            for (int i = 0; i < n; ++i) {
                TreeNode* cur = q.front();
                tmp.push_back(cur -> val);

                if (cur -> left) q.push(cur -> left);
                if (cur -> right) q.push(cur -> right);
                q.pop();
            }
            ans.insert(ans.begin(), tmp);
        }
        return ans;
    }
};