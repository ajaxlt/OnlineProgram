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
    bool isSubEqual(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (!pRoot2) return true;
        if (!pRoot1) return false;
        if (pRoot1 -> val == pRoot2 -> val)
            return isSubEqual(pRoot1 -> left, pRoot2 -> left) && isSubEqual(pRoot1 -> right, pRoot2 -> right);
        else
            return false;
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (!pRoot1 || !pRoot2) return false; //空树不是任意数的子结构
        bool flag = false;
        if (pRoot1 -> val == pRoot2 -> val){
            flag = isSubEqual(pRoot1, pRoot2);
        }
        if (!flag) { //如果头不匹配
            flag = HasSubtree(pRoot1 -> left, pRoot2);
        }
        if (!flag) { //如果左儿子也不匹配，那再试试右儿子
            flag = HasSubtree(pRoot1 -> right, pRoot2);
        }
        return flag;
    }
};