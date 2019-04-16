#include <iostream>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 填充同一层的兄弟节点II(Populating Next Right Pointers in Each Node II)
 *
 * 描述:
 * 给定一个二叉树
 * struct TreeLinkNode {
 *      TreeLinkNode *left;
 *      TreeLinkNode *right;
 *      TreeLinkNode *next;
 * }
 * 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL
 * 初始状态下，所有 next 指针都被设置为 NULL
 *
 * 示例:
 * 给定二叉树，

     1
   /  \
  2    3
 / \    \
4   5    7
调用你的函数后，该二叉树变为：

     1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \    \
4-> 5 -> 7 -> NULL
 * 思路:
 * queue
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