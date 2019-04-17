#include <iostream>
#include <map>
#include <stack>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 有效的括号(Valid Parentheses)
 *
 * 描述:
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 *
 * 有效字符串需满足：
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 注意空字符串可被认为是有效字符串。
 *
 * 思路:
 * 对于一个右括号，我们从该位置出发，向左查找，如果说第一个找到的，且还未被匹配的左括号恰好能与之匹配，则该右括号能够成功匹配
 * 为了简化查找过程，我们应该每匹配一组括号便将他们存储器里删去，以使得下个匹配变得简单
 *
 * 那么栈是最好的选择，我们对括号字符串进行一次遍历
 * 1. 如果当前遍历括号为"左"括号， 则直接入栈
 * (对于"左"括号，我们暂时是无力去裁决该括号字符串的正确性的，因为我们不知道后面是否有合理的右括号与之适配)
 *
 * 2. 如果当前遍历括号为右括号, 可是栈顶是空的, 或者栈顶括号不能与之匹配，则直接返回flase
 * 3. 如果当前遍历括号为右括号, 栈顶可以匹配，则弹出栈顶，表示该组已经匹配
 *
 * 4. 如果遍历完成，但栈不为空，说明有残留括号没有被匹配，则返回false
 * 5. 如果遍历完成，且栈为空，说明括号全部匹配，返回true
 */

class Solution {
public:
    bool isValid(string s) {
        if (s == "") return true;
        map<char, int> mymap;
        stack<int> mystack;
        mymap['('] = 1;
        mymap['['] = 2;
        mymap['{'] = 3;
        mymap[')'] = 4;
        mymap[']'] = 5;
        mymap['}'] = 6;
        for (int i = 0; i < s.length(); ++i) {
            if (mymap[s[i]] <= 3) mystack.push(mymap[s[i]]);
            else if (mystack.empty()) return false;
            else if (mymap[s[i]] - 3 == mystack.top()) mystack.pop();
            else return false;
        }
        if (!mystack.empty()) return false;
        return true;
    }
};