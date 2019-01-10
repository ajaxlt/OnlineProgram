#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 最小覆盖子串(Minimum Window Substring)
 *
 * 描述:
 * 给定一个字符串 S 和一个字符串 T，请在 S 中找出包含 T 所有字母的最小子串
 *
 * 示例:
 * 输入: S = "ADOBECODEBANC", T = "ABC"
 * 输出: "BANC"
 *
 * 说明：
 * 如果 S 中不存这样的子串，则返回空字符串 ""
 * 如果 S 中存在这样的子串，我们保证它是唯一的答案
 *
 * 思路:
 * 滑动窗口
 *
 * 1. 因为我们只需要找到 s 中包含 t 的所有字符的子串即可(次序可以打乱)。因此，需要用 hash 去计数 t 中所有的字符
 * 2. 用滑动窗口界定子串
 *  2.1 开始时，窗口的左口与右口都为0，以右口为遍历变量，遍历 s
 *  如果当前遍历字符在hash中存在，则将哈希值 -1。但是，不能直接就标记说我们解决了 t 中的一个字符
 *  例如， s = "aaa", t = "aab"， 遍历前两个 a 时，没有问题，可以直接标记说，我们解决了 t 的一个字符，但是到第 3 个 'a' 时，却不能再这么认为了
 *  因此，只有在 哈希值 -1 后， 哈希值仍然 大于等于 0， 我们才能使 cnt + 1
 *
 *  2.2 如果cnt = t.size()，说明该窗口已经完全包含了 t 中的所有字符，但是却不能认为该窗口就是最小的
 *  右口恰好是临界没有问题，但是我们不能确保左口也是临界，因此此时需要尝试右移左口
 *
 *  首先，我们要将当前窗口长度和记录的最小长度进行对比，并更新
 *  如果，左窗口这个点，恰好包含了 t 中的元素，则 哈希值 +1
 *
 *  而对于cnt呢，与之前的分析同理，只有当 cnt > 0 时， cnt = cnt - 1
*/
class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || t.size() > s.size()) return "";
        string ans = "";
        int cnt = 0, left = 0, right = 0, minLen = s.size() + 1;
        unordered_map<char, int> myMap;

        for (int i = 0; i < t.size(); ++i) {
            if (myMap.count(t[i])) ++myMap[t[i]];
            else myMap[t[i]] = 1;
        }

        for (; right < s.size(); ++right) {
            if (myMap.count(s[right])) {
                --myMap[s[right]];
                if (myMap[s[right]] >= 0) ++cnt; // 这里，如果 < 0，说明窗口内该字符的计数已经超过 t 中含有的，因此不需要再 ++cnt
                while(cnt == t.size()) {
                    if (right - left + 1 < minLen) {
                        minLen = right - left + 1;
                        ans = s.substr(left, minLen);
                    }
                    if (myMap.count(s[left])) { // 我们要准备往右滑动左边界了，所以要看看左边界是不是包含了t里面的字符
                        ++myMap[s[left]];
                        if (myMap[s[left]] > 0) --cnt;
                    }
                    ++left;
                }
            }
        }
        return ans;
    }
};