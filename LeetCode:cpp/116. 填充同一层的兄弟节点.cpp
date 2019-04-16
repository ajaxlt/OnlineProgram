#include <iostream>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 填充同一层的兄弟节点(Populating Next Right Pointers in Each Node)
 *
 * 描述:
 * 给定一个二叉树
 * struct TreeLinkNode {
 *      TreeLinkNode *left;
 *      TreeLinkNode *right;
 *      TreeLinkNode *next;
 * }
 *
 * 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL
 * 初始状态下，所有 next 指针都被设置为 NULL
 *
 * 说明:
 * 你只能使用额外常数空间。
 * 使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
 * 你可以假设它是一个完美二叉树（即所有叶子节点都在同一层，每个父节点都有两个子节点）。
 *
 * 示例:
 * 给定完美二叉树，

     1
   /  \
  2    3
 / \  / \
4  5  6  7
 调用你的函数后，该完美二叉树变为：

     1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \  / \
4->5->6->7 -> NULL

 * 思路:
 * 完美二叉树，除了叶子点之外，其他任意结点都有左孩子和右孩子
 * 这个问题中需要建立两种新关系，
 * 1. 由于只能在根结点去建立左右结点的新关系，而叶子结点是无法去访问其兄弟结点的
 * 因此，需要在在叶子结点的父节点便建立左右孩子新关系，并且不需要再去访问叶子结点
 *
 * 2. 对于相邻的同层结点(非兄弟结点)，可以利用两者祖先已经建立的新关系进行联系
 * root -> right -> next = root -> next -> left
 *
 */
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
public:
    void connect(TreeLinkNode *root) {
        //只能在根节点去处理左右结点的新关系，而叶子结点是无法访问其兄弟结点的
        //因此，不需要去访问叶子结点
        if (!root || !(root -> left)) return;

        root -> left -> next = root -> right; // 兄弟结点的新联系

        if (root -> next)
            root -> right -> next = root -> next -> left;
        //相邻的同层结点(非兄弟结点)，利用两者祖先新关系进行联系
        connect(root -> left);
        connect(root -> right);
    }
};
