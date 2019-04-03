/*
 * 来源: LintCode
 * 题目: A + B 问题
 *
 * 描述:
 * 给出两个整数 a 和 b , 求他们的和
 *
 * 思路:
 * 位运算
 * 1. xor 只做加法不做进位
 * 2. and << 1 只做进位不做加法
*/
class Solution {
public:
    /**
     * @param a: An integer
     * @param b: An integer
     * @return: The sum of a and b 
     */
    int aplusb(int a, int b) {
        // write your code here
        if (0 == b) return a;
        int cxor = a ^ b;
        int cand = a & b;
        return aplusb(cxor, cand << 1);
    }
};