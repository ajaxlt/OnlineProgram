#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 验证二叉搜索树(Validate Binary Search Tree)
 *
 * 描述:
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树
 * 假设一个二叉搜索树具有如下特征：
 *
 * 节点的左子树只包含小于当前节点的数。
 * 节点的右子树只包含大于当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 *
 * 思路:
 * 递归 + 剪枝
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
    bool inorder(TreeNode* root) {
        bool flag = true;
        if (root -> left) {
            if (root -> val <= root -> left -> val) return false;
            else flag = inorder(root -> left);
        }
        if (!tmp.empty() && tmp.back() >= root -> val) return false;
        else tmp.push_back(root -> val);
        if (flag && root -> right) {
            if (root -> val >= root -> right -> val) return false;
            else flag = inorder(root -> right);
        }
        return flag;
    }
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        return inorder(root);
    }
private:
    vector<int> tmp;
};