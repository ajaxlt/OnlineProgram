#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 按之字型顺序打印二叉树
 *
 * 描述: 请实现一个函数按照之字形打印二叉树，即第一层按照从左到右的顺序打印
 * 第二层按照从右至左的顺序打印
 * 第三层按照从左到右的顺序打印，其他行以此类推
 *
 * 思路:
 * 从上向下打印二叉树的进阶版
 * 可以使用变态STL -> deque(双端队列)
 *
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
     * @param[in] pRoot 根节点
     * @param[in] Q: queue bfs队列
     * @param[in] dq: deque 双端队列，辅助，用于自由调序
     * @param[in] i 当前遍历层数
     * @param[in] j 当前遍历层数总共的元素个数
     * @param[in] k 当前层，遍历的元素下标
     * @return
     */
    vector<vector<int> > Print(TreeNode* pRoot) {
        if (!pRoot) return {};
        vector<vector<int> > rlt;
        queue<TreeNode*> Q; //bfs队列
        deque<int> dq; //辅助队列
        Q.push(pRoot);
        int i = 0, j = 1, k = 0; // i 是当前层， j 是当前层的元素个数, k 是当前记录的个数
        while(!Q.empty()) {
            TreeNode* crt = Q.front();
            if (crt -> left) Q.push(crt -> left);
            if (crt -> right) Q.push(crt -> right);
            if (i % 2 != 0)//奇行头插
                dq.push_front(crt -> val);
            else//偶行尾插
                dq.push_back(crt -> val);
            Q.pop();
            if (++k == j) {
                //如果个数达到本层最大值
                vector<int> tmp;
                while(!dq.empty()){
                    tmp.push_back(dq.front());
                    dq.pop_front();
                }
                rlt.push_back(tmp);
                k = 0;
                ++i;
                j = Q.size();
            }
        }
        return rlt;
    }
};