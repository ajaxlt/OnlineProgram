/*
 * 来源: 2018 校招真题
 * 题目: 交错01串
 *
 * 题目描述:
 * 如果一个01串任意两个相邻位置的字符都是不一样的,我们就叫这个01串为交错01串
 * 例如: "1","10101","0101010"都是交错01串
 * 小易现在有一个01串s,小易想找出一个最长的连续子串,并且这个子串是一个交错01串
 * 小易需要你帮帮忙求出最长的这样的子串的长度是多少
 *
 * 输入描述:
 * 输入包括字符串s,s的长度length(1 ≤ length ≤ 50),字符串中只包含'0'和'1'
 *
 * 输出描述:
 * 输出一个整数,表示最长的满足要求的子串长度
 *
 * 示例1：
 * 输入:
 * 111101111
 *
 * 输出:
 * 3
 *
 * 思路:
 * 一次遍历双指针
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;
    int len = s.size();
    if (len == 1) cout << 1 << endl;
    else {
        int i = 0, Max = -1;
        int prev = s[0] - '0';
        while(i != len) {
            int j = i + 1;
            while (j != len && (s[j] - '0') ^ prev == 1)  prev = s[j++] - '0';
            Max = max(Max, j - i);
            i = j;
        }
        cout << Max << endl;
    }
    return 0;
}