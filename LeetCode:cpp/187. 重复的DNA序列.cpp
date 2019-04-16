#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 重复的DNA序列(Repeated DNA Sequences)
 *
 * 描述:
 * 所有 DNA 由一系列缩写为 A，C，G 和 T 的核苷酸组成，例如：“ACGAATTCCG”
 * 在研究 DNA 时，识别 DNA 中的重复序列有时会对研究非常有帮助
 *
 * 编写一个函数来查找 DNA 分子中所有出现超多一次的10个字母长的序列（子串）
 *
 * 示例:
 * 输入: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 * 输出: ["AAAAACCCCC", "CCCCCAAAAA"]
 *
 * 思路:
 * 1. 遍历输入字符串的长度为 10 的子串，加入哈希表
 * 2. 如果当前子串在哈希表中的计数恰好为2, 则将 目标 加入到输出表中
*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) return ans;
        for (int i = 0; i <= s.size() - 10; ++i) {
            string sub = s.substr(i, 10);
            if (++m[sub] == 2) ans.push_back(sub);
        }
        return ans;
    }
private:
    map<string, int> m;
    vector<string> ans;
};
