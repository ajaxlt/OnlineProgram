#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 从上到下打印二叉树
 *
 * 思路:
 * 常规的二叉树的三种遍历都是递归实现的，基于栈，dfs
 * 本题是层层遍历，应该是用队列实现，bfs
 *
*/

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        if (!root) return {};
        vector<int> rlt;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* crt = q.front();
            if (crt -> left) q.push(crt -> left);
            if (crt -> right) q.push(crt -> right);
            rlt.push_back(crt -> val);
            q.pop();
        }
        return rlt;
    }
};