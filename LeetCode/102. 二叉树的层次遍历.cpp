#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 二叉树的层次遍历(Binary Tree Level Order Traversal)
 *
 * 描述:
 * 给定一个二叉树，返回其按层次遍历的节点值。
 *
 *
 *
 * 思路:
 * 队列实现
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        vector<int> tmp;

        queue<TreeNode*> Q;
        Q.push(root);
        int fa = 1, son = 0;
        while(!Q.empty()) {
            TreeNode* cur = Q.front();
            if (cur -> left) {
                Q.push(cur -> left);
                ++son;
            }
            if (cur -> right) {
                Q.push(cur -> right);
                ++son;
            }
            tmp.push_back(cur -> val);
            Q.pop();
            if (--fa == 0) {
                ans.push_back(tmp);
                tmp.clear();
                fa = son, son = 0;
            }
        }
        return ans;
    }
};