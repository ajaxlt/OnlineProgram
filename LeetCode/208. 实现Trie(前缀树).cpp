/*
 * 来源: LeetCode
 * 题目: 实现Trie(前缀树)(Implement Trie (Prefix Tree))
 *
 * 描述:
 * 实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作
 *
 * 示例:
 * Trie trie = new Trie();
 * trie.insert("apple");
 * trie.search("apple");   // 返回 true
 * trie.search("app");     // 返回 false
 * trie.startsWith("app"); // 返回 true
 * trie.insert("app");
 * trie.search("app");     // 返回 true
 *
 * 说明:
 * 你可以假设所有的输入都是由小写字母 a-z 构成的。
 * 保证所有输入均为非空字符串。
 *
 * 思路:
 * 前缀树是一种多叉树, 根结点中不存储信息，从其子结点结点，可以存放a - z任意一个字符
 * 每条从根节点出发到叶子结点的一条路径代表了一个单词
 */

const int R = 26;
struct TrieNode {
    TrieNode* next[R];
    string str;

    TrieNode() {
        for (int i = 0; i < R; ++i) next[i] = nullptr;
        str = "";
    }
};
class Trie {
private:
    TrieNode* root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        if (word.empty()) return;
        TrieNode* node = root;
        for (int i = 0; i < word.size(); ++i) {
            if (node -> next[word[i] - 'a'] == nullptr) {
                node -> next[word[i] - 'a'] = new TrieNode();
            }
            node = node -> next[word[i] - 'a'];
        }
        if ((node -> str).empty()) node -> str = word;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); ++i) {
            if (node -> next[word[i] - 'a'] == nullptr) return false;
            else node = node -> next[word[i] - 'a'];
        }
        return !(node -> str).empty();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (int i = 0; i < prefix.size(); ++i) {
            if (node -> next[prefix[i] - 'a'] == nullptr) return false;
            else node = node -> next[prefix[i] - 'a'];
        }
        return true;
    }
};