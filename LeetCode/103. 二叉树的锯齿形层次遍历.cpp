#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 二叉树的锯齿形层次遍历(Binary Tree Zigzag Level Order Traversal)
 *
 * 描述:
 * 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）
 *

 * 思路:
 * 双栈法
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        vector<int> tmp;

        stack<TreeNode*> stk1, stk2;
        stk1.push(root);

        int cnt = 0;
        while(!stk1.empty() || !stk2.empty()) {
            stack<TreeNode*> &stk3 = (cnt == 0 ? stk1 : stk2);
            stack<TreeNode*> &stk4 = (cnt == 1 ? stk1 : stk2);
            TreeNode* cur = stk3.top();
            if (cnt == 0) {
                if (cur -> left) stk4.push(cur -> left);
                if (cur -> right) stk4.push(cur -> right);
            }
            else {
                if (cur -> right) stk4.push(cur -> right);
                if (cur -> left) stk4.push(cur -> left);
            }
            tmp.push_back(cur -> val);
            stk3.pop();
            if (stk3.empty()) {
                ans.push_back(tmp);
                tmp.clear();
                cnt = 1 - cnt;
            }
        }
        return ans;
    }
};