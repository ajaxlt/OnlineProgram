#include <iostream>
#include <vector>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 打印从1到最大的n位数
 *
 * 描述: 输入数字n，按顺序打印出从1到最大n位的十进制数。比如输入3，则打印出1、2、3一直到最大的3位数999
 *
 * 思路: 考虑到大数问题，采用数组存放数字的每一位，下标小的为低位
 */
class Solution{
public:
    //打印函数，数组digit按高位至低位存放着n位数的各位， i 表示当前最高位
    void PrintInfo(vector<int>& digit, int i) {
        for (int j = i; j >= 0; --j)
            cout << digit[j];
        cout << endl;
    }
    void Print1ToMaxOfNDigits(int n) {
        vector<int> digit(n + 1, 0);
        int i = 0, cur = 0;
        // i 表示当前最高位， cur表示当前操作位
        while(i < n + 1) {
            ++digit[cur];
            while (digit[cur] == 10) {
                //如果当前操作位为10，则需要进位
                digit[cur] = 0;
                ++digit[++cur];
                //如果当前操作位超过当前最高位，则最高位应当晋1
                if (cur == i + 1) ++i;
            }
            cur = 0; // 进位结束后，当前操作位至0
            if (i == n)
                return;
            PrintInfo(digit, i);
        }
    }
};