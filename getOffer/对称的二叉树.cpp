#include <iostream>
#include <vector>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 对称的二叉树
 *
 * 描述: 请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
 *
 * 思路:
 * 对称的条件是，pS1 的左 = pS2 的右 && pS1的右 = pS2的左
 * 仍然是递归
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
    bool isSymmetrical(TreeNode* pS1, TreeNode* pS2)
    {
        if (!pS1 && !pS2) return true;
        if (!pS1 || !pS2 || pS1 -> val != pS2 -> val) return false;
        return isSymmetrical(pS1 -> left, pS2 -> right) &&
        isSymmetrical(pS1 -> right, pS2 -> left);
    }
    bool isSymmetrical(TreeNode* pRoot)
    {
        return isSymmetrical(pRoot, pRoot);
    }
};
