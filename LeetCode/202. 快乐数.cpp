#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 快乐数(Happy Number)
 *
 * 描述:
 * 编写一个算法来判断一个数是不是“快乐数”
 * 一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和
 * 然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1
 * 如果可以变为 1，那么这个数就是快乐数
 *
 * 示例:
 * 输入: 19
 * 输出: true
 *
 * 解释:
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 *
 * 思路:
 * 简单模拟题
*/

class Solution {
public:
    int trans(int n) {
        int ans = 0;
        while(n) {
            ans += (n % 10) * (n % 10);
            n /= 10;
        }
        return ans;
    }
    bool isHappy(int n) {
        unordered_set<int> mySet;
        while(n != 1) {
            if (mySet.count(n)) return false;
            mySet.insert(n);
            n = trans(n);
        }
        return true;
    }
};