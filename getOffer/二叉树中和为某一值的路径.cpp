#include <iostream>
#include <vector>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 二叉树中和为某一值的路径
 *
 * 描述: 输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径
 * 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径
 * (注意: 在返回值的list中，数组长度大的数组靠前)
 *
 * 思路:
 * 回溯法
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
bool cmp(vector<int>& a,vector<int>& b){
    return a.size() > b.size();
}
class Solution {
public:
    void backTrack(TreeNode* crt, vector<vector<int> >& rlt, vector<int> tmp, int expectNumber, int sum) {
        if (!(crt -> left) && !(crt -> right)) {
            if (expectNumber == sum) rlt.push_back(tmp);
        }
        else {
            if (crt -> left) {
                tmp.push_back(crt -> left -> val);
                backTrack(crt -> left, rlt, tmp, expectNumber, sum + tmp.back());
                tmp.pop_back();
            }
            if (crt -> right) {
                tmp.push_back(crt -> right -> val);
                backTrack(crt -> right, rlt, tmp, expectNumber, sum + tmp.back());
                tmp.pop_back();
            }
        }
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > rlt;
        if (root) backTrack(root, rlt, {root -> val}, expectNumber, root -> val);
        sort(rlt.begin(), rlt.end(), cmp);
        return rlt;
    }
};