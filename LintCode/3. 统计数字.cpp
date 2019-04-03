/*
 * 来源: LintCode
 * 题目: 尾部的零
 *
 * 描述:
 * 计算数字 k 在 0 到 n 中的出现的次数，k 可能是 0~9 的一个值
 *
 * 思路:
 * 暴力
*/
class Solution {
public:
    /**
     * @param k: An integer
     * @param n: An integer
     * @return: An integer denote the count of digit k in 1..n
     */
    int digitCounts(int k, int n) {
        int cnt = 0;
        for (int i = 0; i <= n; ++i) {
            int j = i;
            while(j) {
                int bit = j % 10;
                if (bit == k) ++cnt;
                j /= 10;
            }
        }
        return k == 0 ? cnt + 1 : cnt;
    }
};