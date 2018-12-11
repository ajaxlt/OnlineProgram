#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 和为S的连续正数序列
 *
 * 描述:
 * 找出所有和为S的连续正数序列
 * 例如, S = 100 则返回
 * {{9, 10, 11, 12, 13, 14, 15, 16},
 *  {18, 19, 20, 21, 22}}
 *
 * 注: 输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
 *
 * 思路:
 * 因为序列是连续的，因此可以利用中位数进行讨论
 * 由于严格限制，序列可以由序列的长度推导
 * 1. 长度是奇数，则S必须能够被长度num整除
 * 2. 长度是偶数，则S除以num后为一个半整数
 * 3. 由于要求从开始的数字升序排列，即按长度降序排列，因此需要先求出长度的上界 sqrt(2 * sum)
*/

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> >rlt;
        int up = sqrt(2 * sum);
        for (int num = up; num >= 2; --num) {
            int beg = 0, end = sum;
            if ((num & 1) && (sum % num == 0)) { // 若奇数,且能整除
                int mid = sum / num, delta = num / 2;
                beg = mid - delta; //开始数
                end = mid + delta; //终止数
            }
            else if (!(num & 1) && (sum % num == num / 2)) {// 若偶数，且商为0.5
                int mid = sum / num, delta = num / 2;
                beg = mid + 1 - delta;
                end = mid + delta;
            }
            //else continue;
            if (beg > 0 && end < sum) {
                vector<int> tmp;
                for (int i = beg; i <= end; ++i) tmp.push_back(i);
                rlt.push_back(tmp);
            }
        }
        return rlt;
    }
};
