#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 数字范围按位与(Bitwise AND of Numbers Range)
 *
 * 描述:
 * 给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）
 *
 * 示例 1:
 * 输入: [5,7]
 * 输出: 4
 *
 * 示例 2:
 * 输入: [0,1]
 * 输出: 0
 *
 * 思路:
 * 2进制的最长公共前缀
*/

class Solution1 {
public:
    int rangeBitwiseAnd(int m, int n) {
        int cnt = 0;
        while(n != m) {
            n >>= 1;
            m >>= 1;
            ++cnt;
        }
        return n << cnt;
    }
};

class Solution2 {
public:
    int rangeBitwiseAnd(int m, int n) {
        while(n > m) {
            n &= (n - 1);
        }
        return n;
    }
};