#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 计数质数(Count Primes)
 *
 * 描述:
 * 统计所有小于非负整数 n 的质数的数量
 *
 * 示例:
 * 输入: 10
 * 输出: 4
 * 解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7
 *
 *
 * 思路:
 * 厄拉多塞筛法
 *
*/


class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        vector<bool> isPrime(n, false);
        for (int i = 2; i < n; ++i) {
            if (!isPrime[i]) {
                ++cnt;
                for (int j = 2 * i; j < n; j += i) {
                    isPrime[j] = true;
                }
            }
        }
        return cnt;
    }
};