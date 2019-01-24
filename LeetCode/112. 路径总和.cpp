#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 路径总和(Path Sum)
 *
 * 描述:
 * 给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
 * 说明: 叶子节点是指没有子节点的节点。
 *
 * 示例:
 * 给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
   返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
 *
 * 思路:
 * 同上题，无左时找右，无右时找左
 */


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int cur, int sum) {
        if (!root) return cur == sum;
        else if (!(root -> left)) return hasPathSum(root -> right, cur + root -> val, sum);
        else if (!(root -> right)) return hasPathSum(root -> left, cur + root -> val, sum);
        else return hasPathSum(root -> left, cur + root -> val, sum)
                    || hasPathSum(root -> right, cur + root -> val, sum);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        else return hasPathSum(root, 0, sum);
    }
};