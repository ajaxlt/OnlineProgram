#include <iostream>
#include <vector>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 丑数
 *
 * 描述: 把只包含质因子2、3和5的数称作丑数（Ugly Number）
 * 例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数
 * 求按从小到大的顺序的第N个丑数
 *
 * 思路:
 * 打表法
 * 1. 表中初始存放 1
 * 2. 当我们现在表中已经有前 N - 1 个按顺序排列的丑数时，第 N 个丑数一定时前N - 1里的一个数
 * 或 乘2 或 乘3 或乘5 所得
 * 因此，遍历一遍数组，取之其中或乘2 或乘3 或乘5中最小的，又刚好大于第N - 1的数即可
 *
*/

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index <= 1) return index;
        int rlt[index + 1];
        rlt[1] = 1;
        for (int i = 2; i <= index; ++i) {
            //现在计算第 i 个
            int j, M2, M3, M5;
            for (j = 1; j < i; ++j)
                if (rlt[j] * 5 > rlt[i - 1]) {M5 = rlt[j] * 5; break;}
            for (j = 1; j < i; ++j)
                if (rlt[j] * 3 > rlt[i - 1]) {M3 = rlt[j] * 3; break;}
            for (j = 1; j < i; ++j)
                if (rlt[j] * 2 > rlt[i - 1]) {M2 = rlt[j] * 2; break;}
            rlt[i] = (M5 < M3 ? M5 : M3) < M2 ? (M5 < M3 ? M5 : M3) : M2;
        }
        return rlt[index];
    }
};
