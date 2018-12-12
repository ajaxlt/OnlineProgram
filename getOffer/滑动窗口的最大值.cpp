#include <iostream>
#include <vector>
#include <set>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 滑动窗口的最大值
 *
 * 描述:
 * 给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值
 * 例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口
 * 他们的最大值分别为{4,4,6,6,6,5}
 *
 * 思路:
 * 利用二叉堆, set
*/

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        const int len = num.size();
        if (size == 0 || len < size) return {};
        vector<int> rlt(len - size + 1);
        set<int, greater<int>> mySet;
        int i = 0, j = 0;
        for(; j < size - 1; ++j) mySet.insert(num[j]);
        for(; j < len; ++i, ++j) {
            mySet.insert(num[j]);
            rlt[i] = *mySet.begin();
            mySet.erase(num[i]);
        }
        return rlt;
    }
};
