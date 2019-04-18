/*
 * 来源: LintCode
 * 题目: 二叉树的序列化和反序列化
 *
 *
 * 思路:
 * 基于层次遍历
 *
*/

class TreeNode {
    public:
      int val;
      TreeNode *left, *right;
      TreeNode(int val) {
          this->val = val;
          this->left = this->right = nullptr;
      }
};

class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode * root) {
        string s = "";
        if (root == nullptr) return s;
        queue<TreeNode*> Q;
        Q.push(root);
        s += to_string(root -> val);
        s.push_back(',');
        while(!Q.empty()) {
            TreeNode* cur = Q.front();
            Q.pop();
            if (Q.empty() && cur -> left == nullptr && cur -> right == nullptr) continue;
            if (cur -> left != nullptr) {
                Q.push(cur -> left);
                s += to_string(cur -> left -> val);
            } else s += "#";
            s.push_back(',');
            if (cur -> right != nullptr) {
                Q.push(cur -> right);
                s += to_string(cur -> right -> val);
            } else s += "#";
            s.push_back(',');
        }
        s.pop_back();
        return s;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in
     * "serialize" method.
     */
    TreeNode * deserialize(string &s) {
        if (s.empty()) return nullptr;
        vector<string> tmp;
        for (int i = 0; i < s.size(); ) {
            int j = i;
            for (; j < s.size() && s[j] != ','; ++j);
            tmp.push_back(s.substr(i, j - i));
            i = j + 1;
        }
        //for (auto t : tmp) cout << t << " ";
        //cout << endl;
        TreeNode* root = new TreeNode(atoi(tmp[0].c_str()));
        if (tmp.size() == 1) return root;
        int i = 1;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()) {
            TreeNode* cur = Q.front();
            //cout << cur -> val << endl;
            Q.pop();

            if (i < tmp.size() && tmp[i] != "#") {
                cur -> left = new TreeNode(atoi(tmp[i].c_str()));
                Q.push(cur -> left);
            } else cur -> left = nullptr;
            ++i;
            if (i < tmp.size() && tmp[i] != "#") {
                cur -> right = new TreeNode(atoi(tmp[i].c_str()));
                Q.push(cur -> right);
            } else cur -> right = nullptr;
            ++i;
        }
        return root;
    }
};