#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 二叉树的右视图(Binary Tree Right Side View)
 *
 * 描述:
 * 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值
 *
 * 示例:

输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
 *
 * 思路:
 * 层次遍历的变种
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        vector<int> ans;

        queue<TreeNode*> Q;
        Q.push(root);
        int prev = 1;
        int next = 0;
        while(!Q.empty()) {
            TreeNode* cur = Q.front();
            if (cur -> left) {
                Q.push(cur -> left);
                ++next;
            }
            if (cur -> right) {
                Q.push(cur -> right);
                ++next;
            }
            if (--prev == 0) {
                ans.push_back(cur -> val);
                prev = next;
                next = 0;
            }
            Q.pop();
        }
        return ans;
    }
};