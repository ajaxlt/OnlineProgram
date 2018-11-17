#include <iostream>
#include <vector>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 正则表达式匹配
 *
 * 描述: 实现一个函数用来匹配包括'.'和'*'的正则表达式
 *
 * 思路: 见代码片
*/
class Solution {
public:
    bool match(string s, string p) {
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
            return match(s, p.substr(2)) || (!s.empty() && (s[0] == p[0] || p[0] == '.') && match(s.substr(1), p));
        }
            //4. 如果 p 的长度大于1， 而 p 的第二个字符又不是 '*'
            //则必须比较 p 和 s 的首个字符， 只有他们相等时进行递归，否则直接返回false
        else return !s.empty() && (s[0] == p[0] || p[0] == '.') && match(s.substr(1), p.substr(1));
    }
};