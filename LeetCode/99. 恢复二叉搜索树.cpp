#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 恢复二叉搜索树(Recover Binary Search Tree)
 *
 * 描述:
 * 二叉搜索树中的两个节点被错误地交换
 * 请在不改变其结构的情况下，恢复这棵树
 *
 *
 * 思路:
 * 对于一个标准的二叉搜索树，其中序遍历一定是升序的
 * 我们对本题的输入进行中序遍历，则其一定是一个升序序列，但其中有两个点被交换了
 *
 * 因此，我们需要从一个升序序列中去寻找那两个被交换的点，方法是寻找其中的逆序对
 * 1. 如果逆序对个数为1, 则直接交换两者
 * 2. 如果逆序对个数为2, 则交换第一个的左 与 第二个的右
 *
 * 此外，我们不需要将所有的结点值保存下来，因为每次比较逆序对都是相邻的，我们只需要记录前一个结点值与当前结点值比较即可
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
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root -> left);
        if (prev && prev -> val > root -> val) {
            if (++cnt == 1) {
                lhs = prev;
                rhs = root;
            } else {
                rhs = root;
                return;
            }
        }
        prev = root;
        inorder(root -> right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(lhs -> val, rhs -> val);
    }
private:
    TreeNode *prev = nullptr, *lhs = nullptr, *rhs = nullptr;
    int cnt = 0;
};