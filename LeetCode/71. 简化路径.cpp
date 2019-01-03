#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: x 的平方根(Sqrt(x))
 *
 * 描述:
 * 给定一个文档 (Unix-style) 的完全路径，请进行路径简化
 *
 * 例如，
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 *
 * 边界情况:
 * 你是否考虑了 路径 = "/../" 的情况？
 * 在这种情况下，你需返回 "/"
 * 此外，路径中也可能包含多个斜杠 '/' ，如 "/home//foo/"
 * 在这种情况下，你可忽略多余的斜杠，返回 "/home/foo"
 *
 * 思路:
 * 栈
*/
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> dir;
        int i = 0;
        while (path[i] == '/') ++i;
        int j = i;
        while (i < path.size()) {
            while(path[j] != '/') ++j;
            string cur = path.substr(i, j - i);
            if (cur == ".." && !dir.empty()) dir.pop();
            else if (cur != "." && cur != "..") dir.push(cur);
            while(path[j] == '/' && j < path.size()) ++j;
            i = j;
        }
        string ans = "";
        if (dir.empty()) return "/";
        while(!dir.empty())
        {
            ans = "/" + dir.top() + ans;
            dir.pop();
        }
        return ans;
    }
};