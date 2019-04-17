#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 路径总和II(Path Sum II)
 *
 * 描述:
 * 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径
 * 说明: 叶子节点是指没有子节点的节点
 *
 *
 * 思路:
 * 回溯，保存路径
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void backtrack(TreeNode* next, int root_val, int cur, int sum, vector<int>& tmp) {
        tmp.push_back(root_val);
        pathSum(next, cur + root_val, sum, tmp);
        tmp.pop_back();
    }
    void pathSum(TreeNode* root, int cur, int sum, vector<int>& tmp) {
        if (!(root)) {
            if (cur == sum) ans.push_back(tmp);
        }
        else {
            if (!(root -> left)) backtrack(root -> right, root -> val, cur, sum, tmp);
            else if (!(root -> right)) backtrack(root -> left, root -> val, cur, sum, tmp);
            else {
                backtrack(root -> right, root -> val, cur, sum, tmp);
                backtrack(root -> left, root -> val, cur, sum, tmp);
            }
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) return {};
        vector<int> tmp;
        pathSum(root, 0, sum, tmp);
        return ans;
    }
private:
    vector<vector<int>> ans;
};