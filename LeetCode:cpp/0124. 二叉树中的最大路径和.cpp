#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 二叉树中的最大路径和(Binary Tree Maximum Path Sum)
 *
 * 描述:
 * 给定一个非空二叉树，返回其最大路径和
 * 本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点
 *
 * 示例 1:
 * 输入: [1,2,3]

       1
      / \
     2   3
 * 输出: 6

 * 示例 2:
 * 输入: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

 *输出: 42
 *
 * 思路:
 * 注意，若当前结点作为根节点，则可以左右都算
 * 否则，不可
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int cur = root -> val;
        int left_max = max(0, dfs(root -> left));
        int right_max = max(0, dfs(root -> right));

        ans = max(ans, cur + left_max + right_max);
        return max(cur + left_max, cur + right_max);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
private:
    int ans = INT32_MIN;
};