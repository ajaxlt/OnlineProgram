#include <iostream>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 二叉树的深度
 *
 * 描述:
 * 输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度
 *
 * 思路:
 * 简单题
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
    void getDepth(TreeNode* pRoot, int cnt)
    {
        if (pRoot -> left) getDepth(pRoot -> left, cnt + 1);
        if (pRoot -> right) getDepth(pRoot -> right, cnt + 1);
        depth = max(depth, cnt);
    }
    int TreeDepth(TreeNode* pRoot)
    {
        if (pRoot) getDepth(pRoot, 1);
        return depth;
    }
private:
    int depth = 0;
};