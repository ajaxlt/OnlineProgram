#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 对称二叉树(Symmetric Tree)
 *
 * 描述:
 * 二叉搜索树中的两个节点被错误地交换
 * 请在不改变其结构的情况下，恢复这棵树
 *
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
 *
 * 思路:
 * 简单递归题，左的左等于右的右 且 左的右等于右的左
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* l, TreeNode* r) {
        if (!l || !r) return !l && !r;
        else if (l -> val == r -> val) return isSymmetric(l -> left, r -> right)
                                              && isSymmetric(l -> right, r -> left);
        else return false;
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        else return isSymmetric(root -> left, root -> right);
    }
};