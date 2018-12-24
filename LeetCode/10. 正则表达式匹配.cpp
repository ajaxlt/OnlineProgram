#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 正则表达式匹配(Regular Expression Matching)
 *
 * 描述:
 * 给定一个字符串 (s) 和一个字符模式 (p)。实现支持 '.' 和 '*' 的正则表达式匹配
 * '.' 匹配任意单个字符
 * '*' 匹配零个或多个前面的元素
 * 匹配应该覆盖整个字符串 s ，而不是部分字符串
 *
 * 说明:
 * s 可能为空，且只包含从 a-z 的小写字母
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *

 *
 * 思路:
 * 见代码注释
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        //1. 如果 p 是空的，则匹配与否取决于 s 是否空
        if(p.empty()) return s.empty();

        //2. 如果 p 的长度是 1， 当且仅当 s 的长度也是 1， 且 p[0] 和 s[0]匹配
        //注意，即便 p = “*”, 这也是无法匹配的，因为 * 之前必须有另一个字符才作效
        if(p.size() == 1) return s.size() == 1 && (s[0] == p[0] || p[0] == '.');

        //3. 如果 p 的长度大于 1， 且 p 的第二个字符是 '*'
        //这里， * 可以 匹配 0 个至 inf 个
        if(p[1] == '*'){
            //3.1. 当匹配 0 个， 即直接去掉 p 的前 2 个字符，而 s 不动， 进行匹配
            //3.2. 当匹配 1+ 个， 那么，首要条件是 p[0] 和 s[0]匹配
            //然后可以选择直接去掉 s 的第 1 个字符，而 p 不动， 进行递归， 此时 s 首先不能为空
            return isMatch(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p));
        }
            //4. 如果 p 的长度大于1， 而 p 的第二个字符又不是 '*'
            //则必须比较 p 和 s 的首个字符， 只有他们相等时进行递归，否则直接返回false
        else return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
    }
};

int main() {
    Solution solu;
    string s = "ab", p = ".*";
    cout << solu.isMatch(s, p) << endl;
}