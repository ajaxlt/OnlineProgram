#include <iostream>
#include <vector>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 树的子结构
 *
 * 描述: 输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
 *
 * 思路:
 * 首先要在树A上找到一个结点，该结点的值与 B 树的根节点值一致
 * 找到后，再逐一比较左右子树
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
    bool helper(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) return root2 == nullptr;
        if (root2 == nullptr) return true;
        if (root1 -> val == root2 -> val) return helper(root1->left, root2->left) && helper(root1->right, root2->right);
        else return false;
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
        if (pRoot1 == nullptr || pRoot2 == nullptr) return false;
        if (helper(pRoot1, pRoot2)) return true;
        else return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }
};
