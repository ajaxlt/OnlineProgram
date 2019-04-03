/*
 * 来源: LintCode
 * 题目: 丑数 II
 *
 * 描述:
 * 设计一个算法，找出只含素因子2，3，5 的第 n 小的数
 * 符合条件的数如：1, 2, 3, 4, 5, 6, 8, 9, 10, 12..
 *
 * 思路:
 * 动态规划
 * 第 k 个丑数 = 前 k - 1 个丑数中，每个数 *2, *3, *5 后，恰好大于第 k - 1 个丑数的较小者
 *
*/
class Solution {
public:
    /**
     * @param n: An integer
     * @return: return a  integer as description.
     */
    int nthUglyNumber(int n) {
        if (n == 1) return 1;

        vector<int> ugly(n + 1);
        ugly[1] = 1;
        for (int i = 2; i <= n; ++i) {
            int j, u2, u3, u5, u;
            for (j = 1; j < i; ++j)
                if (ugly[j] * 2 > ugly[i - 1]) {u2 = ugly[j] * 2; break;}
            u = u2;
            for (j = 1; j < i; ++j)
                if (ugly[j] * 3 > ugly[i - 1]) {u3 = ugly[j] * 3; break;}
            u = min(u, u3);
            for (j = 1; j < i; ++j)
                if (ugly[j] * 5 > ugly[i - 1]) {u5 = ugly[j] * 5; break;}
            u = min(u, u5);

            ugly[i] = u;
        }

        return ugly[n];
    }
};