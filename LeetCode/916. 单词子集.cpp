#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 单词子集(Word Subsets)
 *
 * 描述:
 * 我们给出两个单词数组 A 和 B。每个单词都是一串小写字母
 * 现在，如果 b 中的每个字母都出现在 a 中，包括重复出现的字母，那么称单词 b 是单词 a 的子集。 例如，“wrr” 是 “warrior” 的子集，但不是 “world” 的子集。
 * 如果对 B 中的每一个单词 b，b 都是 a 的子集，那么我们称 A 中的单词 a 是通用的
 * 你可以按任意顺序以列表形式返回 A 中所有的通用单词
 *
 * 示例 1：
 * 输入：A = ["amazon","apple","facebook","google","leetcode"], B = ["e","o"]
 * 输出：["facebook","google","leetcode"]
 *
 * 示例 2：
 * 输入：A = ["amazon","apple","facebook","google","leetcode"], B = ["l","e"]
 * 输出：["apple","google","leetcode"]
 *
 * 示例 3：
 * 输入：A = ["amazon","apple","facebook","google","leetcode"], B = ["e","oo"]
 * 输出：["facebook","google"]
 *
 * 示例 4：
 * 输入：A = ["amazon","apple","facebook","google","leetcode"], B = ["lo","eo"]
 * 输出：["google","leetcode"]
 *
 * 示例 5：
 * 输入：A = ["amazon","apple","facebook","google","leetcode"], B = ["ec","oc","ceo"]
 * 输出：["facebook","leetcode"]
 *
 * 思路:
 * 用map计数
 * 但是，对于 B 我们需要对其进行合并, 即对于 B 里可能含有的一个字符 x
 * 我们需要取 B 中的 b 含有最多的即可
 *
 * 暴力法会超时
 */

class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> m1(len, 0);
        for (auto b : B) {
            vector<int> m2(len, 0);
            for (auto c : b) {
                ++m2[c - 'a'];
                if (m1[c - 'a'] < m2[c - 'a']) {
                    m1[c - 'a'] = m2[c - 'a'];
                }
            }
        }
        for (auto a : A) {
            bool flag = true;
            vector<int> m3(len, 0);
            for (auto c : a) ++m3[c - 'a'];
            for (int i = 0; i < len; ++i)
                if (m3[i] < m1[i]) {
                    flag = false;
                    break;
                }
            if (flag) ans.push_back(a);
        }
        return ans;
    }
private:
    int len = 'z' - 'a' + 1;
    vector<string> ans;
};