#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 扰乱字符串(Scramble String)
 *
 * 描述:
 * 给定一个字符串 s1，我们可以把它递归地分割成两个非空子字符串，从而将其表示为二叉树。
 * 下图是字符串 s1 = "great" 的一种可能的表示形式。

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
在扰乱这个字符串的过程中，我们可以挑选任何一个非叶节点，然后交换它的两个子节点。

例如，如果我们挑选非叶节点 "gr" ，交换它的两个子节点，将会产生扰乱字符串 "rgeat"

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
我们将 "rgeat” 称作 "great" 的一个扰乱字符串。

同样地，如果我们继续将其节点 "eat" 和 "at" 进行交换，将会产生另一个新的扰乱字符串 "rgtae"

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
我们将 "rgtae” 称作 "great" 的一个扰乱字符串。

 * 给出两个长度相等的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串
 *
 * 思路:
 * 递归解决
 * 1. 首先判断两串的长度是否相等，且是否是同一个串的全排列
 * 2. 对待判别串，对其进行 len - 1 种切分，对于左边部分left，若left是原串的最左边或者最右边，则分２段继续递归
*/

class Solution {
public:
    bool isSame(const string& s1, const string& s2) {
        vector<int> Mymap(256, 0);
        int cnt = 0;
        for (int i = 0; i < s1.size(); ++i) {
            ++Mymap[s1[i] - '0'];
            ++cnt;
        }
        for (int i = 0; i < s2.size(); ++i) {
            if (Mymap[s2[i] - '0'] > 0) {
                --Mymap[s2[i] - '0'];
                --cnt;
            }
        }
        return !cnt;
    }
    bool backTrack(const string& s1, const string& s2) {
        if (s2.size() == 1) return true;
        else {
            for (int i = 1; i < s2.size(); ++i) {
                bool flag = false;
                string s2_left = s2.substr(0, i);
                string s2_right = s2.substr(i);


                if (isSame(s1.substr(0, i), s2_left))
                    flag = backTrack(s1.substr(0, i), s2_left)
                           && backTrack(s1.substr(i), s2_right);

                if (!flag && isSame(s1.substr(s1.size() - i), s2_left))
                    flag = backTrack(s1.substr(s1.size() - i), s2_left)
                           && backTrack(s1.substr(0, s1.size() - i), s2_right);

                if (flag) return true;
            }
            return false;
        }
    }
    bool isScramble(string s1, string s2) {
        int len1 = s1.size(), len2 = s2.size();
        if (len1 != len2) return false;
        if (!isSame(s1, s2)) return false;
        if (len1 <= 3) return true;
        return backTrack(s1, s2);
    }
};