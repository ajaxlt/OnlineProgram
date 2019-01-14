#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 不同的二叉搜索树 II(Unique Binary Search Trees II)
 *
 * 描述:
 * 给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树
 *
 * 示例:
 * 输入: 3
 * 输出:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释:
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 *
 * 思路:
 * 如果根节点取 i, 则左子树只能取 beg -> i - 1, 右子树只能取 i + 1 -> end
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        else return dfs(1, n);
    }
    vector<TreeNode*> dfs(int beg, int end) {
        if (beg > end) return {nullptr};
        else {
            vector<TreeNode*> ans;
            for (int i = beg; i <= end; ++i) {
                vector<TreeNode*> left = dfs(beg, i - 1);
                vector<TreeNode*> right = dfs(i + 1, end);

                for (auto l : left) {
                    for (auto r : right) {
                        TreeNode* root = new TreeNode(i);
                        root -> left = l;
                        root -> right = r;
                        ans.push_back(root);
                    }
                }
            }
            return ans;
        }
    }
};