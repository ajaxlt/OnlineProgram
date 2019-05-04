#include <iostream>
#include <vector>
using namespace std;
/*
 * ��Դ: ��ָOffer
 * ��Ŀ: �����ӽṹ
 *
 * ����: �������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
 *
 * ˼·:
 * ����Ҫ����A���ҵ�һ����㣬�ý���ֵ�� B ���ĸ��ڵ�ֵһ��
 * �ҵ�������һ�Ƚ���������
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
    bool helper(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) return root2 == nullptr;
        if (root2 == nullptr) return true;
        if (root1 -> val == root2 -> val) return helper(root1->left, root2->left) && helper(root1->right, root2->right);
        else return false;
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
        if (pRoot1 == nullptr || pRoot2 == nullptr) return false;
        if (helper(pRoot1, pRoot2)) return true;
        else return HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }
};
