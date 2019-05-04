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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /**
    * @param[in] pre: 前序遍历
    * @param[in] vin: 中序遍历
    * @param[in] l1: 前序遍历左端点(闭)
    * @param[in] r1: 前序遍历右端点(闭)
    * @param[in] l2: 中序遍历左端点(闭)
    * @param[in] r2: 中序遍历右端点(闭)
    */
    TreeNode* reConstructBinaryTree(vector<int>& pre, vector<int>& vin, 
                                    int l1, int r1, int l2, int r2) {
        if (l1 > r1) return nullptr;
        // 前序遍历的起点一定是 根
        TreeNode* root = new TreeNode(pre[l1]);
        int i = l2; // 从中序遍历的左端点开始寻找
        while(vin[i] != pre[l1]) ++i; // 寻找根结点在中序遍历的下标
        // 对数组切片处理
        root->left = reConstructBinaryTree(pre, vin, l1 + 1, l1 + i - l2, l2, i - 1);
        root->right = reConstructBinaryTree(pre, vin, l1 + i - l2 + 1, r1, i + 1, r2);
        return root;
        
    }
    TreeNode* reConstructBinaryTree(vector<int>& pre, vector<int>& vin) {
        int len1 = pre.size(), len2 = vin.size();
        if (len1 != len2) return nullptr;
        return reConstructBinaryTree(pre, vin, 0, len1 - 1, 0, len2 - 1);
    }
};