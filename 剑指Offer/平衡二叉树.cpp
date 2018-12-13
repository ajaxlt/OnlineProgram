#include <iostream>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 平衡二叉树
 *
 * 描述:
 * 输入一棵二叉树，判断该二叉树是否是平衡二叉树
 *
 * 思路:
 * 平衡二叉树是指，对于该二叉树上的**任意**结点，左右子树的深度差不超过1
 *
 * 判断思路一定是先遍历结点的左右子树，再遍历到结点，即后序遍历 左-右-根
 *
 * 1. 递归到叶子结点时，一定返回true，并将此时的深度置0
 * 2. 结点的深度为 max(l_depth, r_depth) + 1, 当然，如果左右子树的长度差过1则直接返回false
 * 3. 深度是倒着计算的，因此需要用pass value by pointer或者pass value by reference，实时记录当前的深度
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
    bool compareDepth(TreeNode* pRoot, int& cnt)
    {
        if (!pRoot) return true;

        int lcnt = 0, rcnt = 0;
        if (compareDepth(pRoot -> left, lcnt) && compareDepth(pRoot -> right, rcnt)) {
            if (abs(lcnt - rcnt) <= 1) {
                cnt = 1 + max(lcnt, rcnt);
                return true;
            }
        }
        return false;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int cnt = 0;
        return compareDepth(pRoot, cnt);
    }
};