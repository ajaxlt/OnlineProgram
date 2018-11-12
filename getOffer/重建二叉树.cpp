#include <iostream>
#include <vector>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 重建二叉树
 *
 * 描述: 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
 * 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 *
 * 思路:
 * 1. 前序 + 中序 可以重构
 * 2. 后序 + 中序 可以重构
 * 3. 前序 + 后序 不可重构
 * 故,  给定中序才能重构
 * 当然, 元素是不能重复的
 *
 * 前序 + 中序 重构的思路：
 * 前序的首元素一定是根节点
 * 在中序中找到该元素的位置，则左边是左子数，右边是右子数
 * 可以由此统计出左子树包含的元素个数以及右子树包含的元素数目
 * 递归
*/

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* reConstructCore(vector<int> pre,
                              vector<int> vin,
                              int pre_beg,
                              int pre_end,
                              int vin_beg,
                              int vin_end) {
        int root_val = pre[pre_beg]; // 前序的首个必然是根节点
        TreeNode* root = new TreeNode(root_val);// 初始化根节点

        // 递归终点
        if(pre_beg == pre_end) { // 只有一个元素时，判断合法性
            if (vin_beg == vin_end && pre[pre_beg] == vin[vin_beg])
                return root;
            else throw ("Invalid input.");
        }
        // 若不是终点，则找根节点在中序的位置
        int vin_root = vin_beg;
        for (; vin_root <= vin_end && vin[vin_root] != root -> val; ++vin_root);
        if (vin_root == vin_end && vin[vin_root] != root -> val)
            throw ("Invalid input.");

        //左右分离
        int leftLength = vin_root - vin_beg;
        int rightLength = vin_end - vin_root;
        if (leftLength > 0)
            root -> left = reConstructCore(pre, vin, pre_beg + 1, pre_beg + leftLength, vin_root - leftLength, vin_root - 1);
        if (rightLength > 0)
            root -> right = reConstructCore(pre, vin, pre_beg + leftLength + 1, pre_end, vin_root + 1, vin_end);
        return root;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (pre.empty() || vin.empty()) return nullptr;
        else return reConstructCore(pre, vin, 0, pre.size() - 1, 0, vin.size() - 1);
    }
};