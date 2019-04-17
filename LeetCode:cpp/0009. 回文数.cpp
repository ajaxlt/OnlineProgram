#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 回文数(Palindrome Number)
 *
 * 描述:
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 *
 *
 * 思路:
 * 简单题
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int rev_x = 0, tmp = x;
        while (tmp) {
            rev_x = rev_x * 10 + tmp % 10;
            tmp /= 10;
        }
        return rev_x == x;
    }
};