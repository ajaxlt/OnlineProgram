#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 二叉树的层次遍历 II(Binary Tree Level Order Traversal II)
 *
 * 描述:
 * 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树
 *
 * 思路:
 * 根节点在中间
 */
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums, int beg, int end) {
        int mid = (beg + end) / 2;
        int root_val = nums[mid];
        TreeNode* root = new TreeNode(root_val);

        if (beg == end) return root;

        int l_len = mid - beg;
        int r_len = end - mid;
        if (l_len > 0) root -> left = sortedArrayToBST(nums, beg, mid - 1);
        if (r_len > 0) root -> right = sortedArrayToBST(nums,mid + 1, end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
};