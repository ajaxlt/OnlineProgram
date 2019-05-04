#include <iostream>
#include <string.h>
#include <string>
#include <queue>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 矩形覆盖
 *
 * 描述:
 * 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形
 * 请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/

class Solution {
public:
    int rectCover(int n) {
        if (n <= 0) return 0;
        if (n <= 2) return n;
        int pre = 2, ppre = 1;
        int ans = 0;
        for (int i = 3; i <= n; ++i) {
            ans = pre + ppre;
            ppre = pre;
            pre = ans;
        }
        return ans;
    }
};
