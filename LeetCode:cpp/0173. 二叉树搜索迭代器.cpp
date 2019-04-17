#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 二叉搜索树迭代器(Binary Search Tree Iterator)
 *
 * 描述:
 * 实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器
 * 调用 next() 将返回二叉搜索树中的下一个最小的数
 *
 * 思路:
 * 1. 初始化时，先将左子树全部入栈(此时堆顶是最小的)
 * 2. 取最小值时, 弹出堆顶, 并将右儿子以及其左子树全部入栈
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while(root) {
            stk.push(root);
            root = root -> left;
        }
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* minNode = stk.top();
        stk.pop();
        int minVal = minNode -> val;
        minNode = minNode -> right;
        while(minNode) {
            stk.push(minNode);
            minNode = minNode -> left;
        }
        return minVal;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }
private:
    stack<TreeNode*> stk;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
