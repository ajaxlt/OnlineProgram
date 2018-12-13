#include <iostream>

using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 二叉搜索树的第k个结点
 *
 * 描述:
 * 给定一棵二叉搜索树，请找出其中的第k小的结点
 * 例如 (5，3，7，2，4，6，8) 中，按结点数值大小顺序第三小结点的值为4
 *
 * 思路:
 * BST -> 左 < 根 < 右
 * 因此使用中序遍历可以恰好按升序输出各个结点
 *
 * 递归函数的写法:
 * 0. 设定当前目标target
 *
 * 1. 若左不空，先走左到底
 * 2. 若左空，判断本体(本体定不空，否则便不会进入本体的递归层)，计数先+1然后判断是否到界
 * 3. 若左空，加上本体之后计数仍未到界，则需要寻求右
 *
 * 4. 若全部遍历完，计数仍未到达界，则1. 2. 3.都无法进入，此时直接返回target
 * 因此应在函数首将target初始化为nullptr
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
    TreeNode* inorderTravel(TreeNode* pRoot, int k) {
        TreeNode* tar = nullptr;

        if(pRoot -> left) tar = inorderTravel(pRoot -> left, k);

        // 左边走完, 算上自己如果刚好
        if(!tar && ++cnt == k) tar = pRoot;

        //左边走完，而算上自己还不够的话，寻求右边
        if(!tar && pRoot -> right) tar = inorderTravel(pRoot -> right, k);

        return tar;
    }
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if (!pRoot || k <= 0) return nullptr;
        else return inorderTravel(pRoot, k);
    }
private:
    int cnt = 0;
};