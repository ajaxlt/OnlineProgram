#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 同构字符串(Isomorphic Strings)
 *
 * 描述:
 * 给定两个字符串 s 和 t，判断它们是否是同构的
 * 如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的
 * 所有出现的字符都必须用另一个字符替换，同时保留字符的顺序
 * 两个字符不能映射到同一个字符上，但字符可以映射自己本身
 *
 * 示例 1:
 * 输入: s = "egg", t = "add"
 * 输出: true
 *
 * 示例 2:
 * 输入: s = "foo", t = "bar"
 * 输出: false
 *
 * 示例 3:
 * 输入: s = "paper", t = "title"
 * 输出: true
 *
 *
 * 思路:
 * map + set
*/


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> m;
        set<char> ss;
        for (int i = 0; i < s.size(); ++i) {
            if (!m.count(s[i])) {
                if (ss.count(t[i])) return false;
                else {
                    m[s[i]] = t[i];
                    ss.insert(t[i]);
                }
            }
            else if (m[s[i]] != t[i]) return false;
        }
        return true;
    }
};