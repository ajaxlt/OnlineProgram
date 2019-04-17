/*
 * 来源: LeetCode
 * 题目: 添加与搜索单词 - 数据结构设计(Add and Search Word - Data structure design)
 *
 * 描述:
 * 设计一个支持以下两种操作的数据结构：
 * void addWord(word)
 * bool search(word)
 * search(word) 可以搜索文字或正则表达式字符串，字符串只包含字母
 * 或 a-z 。 . 可以表示任何一个字母
 *
 * 示例:
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 *
 * 说明:
 * 你可以假设所有单词都是由小写字母 a-z 组成的。
 *
 * 思路:
 * 前缀树的应用。对于 "."，用回溯法
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
class WordDictionary {
private:
    TrieNode* root;

public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
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

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word, TrieNode* node) {
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] == '.') {
                for (int j = 0; j < R; ++j) {
                    if ((node -> next[j]) != nullptr && search(word.substr(i + 1), node -> next[j])) return true;
                }
                return false;
            }
            else if (node -> next[word[i] - 'a'] == nullptr) return false;
            else node = node -> next[word[i] - 'a'];
        }
        return !(node -> str).empty();
    }
    bool search(string word) {
        return search(word, root);
    }
};

