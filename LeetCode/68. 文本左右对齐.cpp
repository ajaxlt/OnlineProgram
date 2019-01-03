#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 文本左右对齐(Text Justification)
 *
 * 描述:
 * 给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本
 * 你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符
 * 要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
 * 文本的最后一行应为左对齐，且单词之间不插入额外的空格
 *
 * 说明:
 * 单词是指由非空格字符组成的字符序列
 * 每个单词的长度大于 0，小于等于 maxWidth
 * 输入单词数组 words 至少包含一个单词
 *
 * 示例 1:
 * 输入:
 * words = ["This", "is", "an", "example", "of", "text", "justification."]
 * maxWidth = 16
 * 输出:
 * [
 *  "This    is    an",
 *  "example  of text",
 *  "justification.  "
 * ]
 *
 * 示例 2:
 * 输入:
 * words = ["What","must","be","acknowledgment","shall","be"]
 * maxWidth = 16
 * 输出:
 * [
 *  "What   must   be",
 *  "acknowledgment  ",
 *  "shall be        "
 * ]
 *
 * 解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be"
 * 因为最后一行应为左对齐，而不是左右两端对齐。
 * 第二行同样为左对齐，这是因为这行只包含一个单词
 *
 *
 * 思路:
 * 逻辑题
*/
class Solution {
public:
    inline void addBlank(string& tmp, int n) {
        for (int i = 0; i < n; ++i) tmp += " ";
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        string tmp = "";
        int i = 0, j = 0, cnt = 0;
        while(j < words.size()) {
            if (cnt + words[j].size() + j - i > maxWidth) {
                int space = j - 1 - i;
                if (space == 0) {
                    tmp += words[i];
                    addBlank(tmp, maxWidth - words[i].size());
                } else {
                    int ave = (maxWidth - cnt) / space;
                    int res = (maxWidth - cnt) % space;
                    int k = i;
                    while(k < j - 1) {
                        tmp += words[k];
                        if (k - i < res) addBlank(tmp, ave + 1);
                        else addBlank(tmp, ave);
                        ++k;
                    }
                    tmp += words[j - 1];
                }
                ans.push_back(tmp);
                tmp = "";
                cnt = 0;
                i = j;
            } else if (j == words.size() - 1) {
                int k = i;
                cnt = 0;
                while(k <= j) {
                    cnt += words[k].size();
                    tmp += words[k];
                    if (cnt != maxWidth) {
                        tmp += " ";
                        ++cnt;
                    }
                    ++k;
                }
                addBlank(tmp, maxWidth - cnt);
                ans.push_back(tmp);
                break;
            }
            else {
                cnt += words[j].size();
                ++j;
            }
        }
        return ans;
    }
};