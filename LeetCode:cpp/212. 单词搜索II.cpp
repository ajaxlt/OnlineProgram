/*
 * 来源: LeetCode
 * 题目: 单词搜索II(Word Search II)
 *
 * 描述:
 * 给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词
 *
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格
 * 同一个单元格内的字母在一个单词中不允许被重复使用
 *
 * 示例:
 * 输入:
 * words = ["oath","pea","eat","rain"] and board =
 * [
 *  ['o','a','a','n'],
 *  ['e','t','a','e'],
 *  ['i','h','k','r'],
 *  ['i','f','l','v']
 * ]
 *
 * 输出: ["eat","oath"]
 * 说明:
 * 你可以假设所有的输入都是由小写字母 a-z 构成的。
 * 保证所有输入均为非空字符串
 *
 * 思路:
 * 前缀树 + 回溯
 */

const int R = 26;
class TrieNode {
public:
    bool isWord;
    vector<TrieNode*> next;
    TrieNode() : isWord(false), next(R, nullptr) {}
};
class Solution {
private:
    TrieNode *root;
    void addWord(string word) {
        TrieNode *node = root;

        for (char c : word) {
            if (node -> next[c - 'a'] == nullptr) {
                node -> next[c - 'a'] = new TrieNode();
            }
            node = node -> next[c - 'a'];
        }
        node -> isWord = true;
    }
public:
    int rows;
    int cols;
    vector<vector<bool>> vis;
    vector<string> ans;
    int G[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
public:
    void dfs(vector<vector<char>>& board, string &str, TrieNode* node, int row, int col) {
        if (node == nullptr) return;
        if (node -> isWord) {
            ans.push_back(str);
            node -> isWord = false;//防止重复
        }
        string tmpstr;
        for (int g = 0; g < 4; ++g) {
            int nrow = row + G[g][0], ncol = col + G[g][1];
            if (nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols && node -> next[board[nrow][ncol] - 'a'] != nullptr && !vis[nrow][ncol]) {
                vis[nrow][ncol] = true;
                tmpstr = str + char(board[nrow][ncol]);
                dfs(board, tmpstr, node->next[board[nrow][ncol] - 'a'], nrow, ncol);
                vis[nrow][ncol] = false;
            }
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        rows = board.size();
        if (rows == 0) return {};
        cols = board[0].size();
        vis = vector<vector<bool>>(rows, vector<bool>(cols, false));

        root = new TrieNode();

        for (auto word : words) addWord(word);

        string str;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (root->next[board[row][col] - 'a'] != nullptr) {//搜索
                    str = "";
                    str += char(board[row][col]);
                    vis[row][col] = true;//标记使用
                    dfs(board, str, root -> next[board[row][col] - 'a'], row, col);
                    vis[row][col] = false;//取消使用
                }
            }
        }
        return ans;
    }
};
