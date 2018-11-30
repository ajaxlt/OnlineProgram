#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 整数中1出现的次数(从1到n整数中1出现的次数)
 *
 * 描述:
 * 输入一个整数n，统计1~n这n个整数中1出现的次数
 *
 * 思路：
 * 1. 从最低位到最高位逐一统计1出现的次数
 * 2. 对于 i 位, 1的个数将受限于，当前位，当前位以上位，以及当前位下一位
 *    我们分别用curr, prev 和 next 表示
 *    2.1 如果 curr 大于 1, 则 cnt += (prev + 1) * i
 *    2.2 如果 curr 等于 1, 则 cnt += prev * i + next + 1
 *    2.3 如果 curr 等于 0, 则 cnt += prev * i
*/
class Solution {
public:
    /**
     *
     * @param cnt[in, out] 计数变量
     * @param i 遍历位(1, 10, 100, ...)
     * @param curr 当前位
     * @param prev 高于当前位的所有位
     * @param next 低于当前位的下一位
     * @return cnt
     */
    int NumberOf1Between1AndN_Solution(int n)
    {
        int cnt = 0;
        int i = 1;
        int curr, prev, next;
        while(n / i) {
            curr = n / i % 10;
            prev = n / i / 10;
            next = n - n / i * i;
            if (curr > 1) cnt += (prev + 1) * i;
            else if (curr == 1) cnt += prev * i + next + 1;
            else cnt += prev * i;
            i *= 10;
        }
        return cnt;
    }
};