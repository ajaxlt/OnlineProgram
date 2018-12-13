#include <iostream>
#include <string.h>
#include <string>
#include <queue>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 把二叉树打印成多行
 *
 * 描述:
 * 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行
 *
 * 思路:
 * 辗转法
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
    vector<vector<int> > Print(TreeNode* pRoot) {
        if (!pRoot) return {};
        vector<vector<int> > rlt;
        queue<TreeNode*> Q;
        Q.push(pRoot);
        int cnt[2] = {1, 0}, idx = 0;
        //cnt[0] 和 cnt[1] 其中一个表示本层数量，另外一个表示下层数量
        //cnt[idx] 表示的是本层数量
        vector<int> tmp;
        while(!Q.empty()) {
            TreeNode* cur = Q.front();
            if (cur -> left) {
                ++cnt[1 - idx];
                Q.push(cur -> left);
            }
            if (cur -> right) {
                ++cnt[1 - idx];
                Q.push(cur -> right);
            }
            tmp.push_back(cur -> val);
            Q.pop();
            if (--cnt[idx] == 0) {
                rlt.push_back(tmp);
                tmp.clear();
                idx = 1 - idx;
            }
        }
        return rlt;
    }
};
