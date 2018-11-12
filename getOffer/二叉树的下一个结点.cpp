#include <iostream>
#include <vector>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 二叉树的下一个结点
 *
 * 描述: 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
 * 注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
 *
 * 思路:
 * 见代码块
 *
*/

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (pNode == nullptr) return nullptr;
        // 1. 如果说 p 有右子树，那么下个就是右子树的最左边
        if (pNode -> right) {
            TreeLinkNode *curNode = pNode -> right;
            while(curNode -> left) curNode = curNode -> left;
            return curNode;
        }
            // 2. 如果 p 没有右子树, 那么它的下一个一定会先追溯他的父亲
        else {
            // 没有父亲，则返回空
            // 如果它是它父亲的左，直接返回
            // 如果是它父亲的右，往父亲方向迭代，直到某刻是父亲左
            TreeLinkNode *curNode = pNode;
            TreeLinkNode *pp = pNode -> next;//父结点
            while(pp && curNode == pp -> right) {
                curNode = pp;
                pp = pp -> next;
            }
            return pp;
        }
    }
};