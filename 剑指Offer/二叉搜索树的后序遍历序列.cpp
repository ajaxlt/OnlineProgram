#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 二叉搜索树的后序遍历序列
 *
 * 描述: 输入一个整数数组，判断该数组是不是某二叉搜索树的后续遍历的结果。
 * (假设输入的数组的任意两个数字都互不相同)
 *
 * 思路:
 * 二叉搜索树(BST): 左 < 根 < 右
 * 后序遍历: 左 -> 右 -> 根
 *
 * 1. 如果给定序列是某一潜在BST的后序遍历，那么根节点一定是序列的末尾
 * 2. 序列除了某尾(根)之外，一部分是左，一部分是右，且左右是不会交错的
 * 设序列下标区间为[p, r]
 * 首先我们需要从序列头开始找到第一个大于根值的下标 q，该下标是左的截止，亦是右的起始
 * 如果 [q, r) 之间还存在小于根值的元素，则其不是BST
 * 如果该层满足条件，则还需对其左右进行递归调用
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
    /**
     *
     * @param seq[in] 给定序列
     * @param p[in] 当前起始(闭)
     * @param r[in] 当前终止(闭)
     * @param q[in] 左右分割点
     * @return
     */
    bool VerifySub(vector<int> seq, int p, int r) {
        if(p >= r) return true;
        int root = seq[r]; // 根
        int q = p;
        for (; q < r && seq[q] < root; ++q);
        for (int k = q; k < r; ++k) {
            if (seq[k] < root) return false;
        }
        return VerifySub(seq, p, q - 1) && VerifySub(seq, q, r - 1);
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty()) return false; // 空树不是？ 我去你妈比
        return VerifySub(sequence, 0, sequence.size() - 1);
    }
};