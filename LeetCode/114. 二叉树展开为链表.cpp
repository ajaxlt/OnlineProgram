#include <iostream>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 二叉树展开为链表(Flatten Binary Tree to Linked List)
 *
 * 描述:
 * 给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树
 *
 * 示例:
 * 给定一个二叉树，原地将它展开为链表
 * 例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

 * 思路:
 * 后序遍历
 * 递归至最左子树, 断开其与根结点的联系，设置根节点的右子树为其原来的左子树，而左子树的右子树为根结点的右子树
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        //后序遍历
        flatten(root -> left);
        flatten(root -> right);

        TreeNode* tmp = root -> right;
        root -> right = root -> left;
        root -> left = nullptr;

        while(root -> right) root = root -> right;
        root -> right = tmp;
    }
};