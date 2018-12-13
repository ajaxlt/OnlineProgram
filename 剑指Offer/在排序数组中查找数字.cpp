#include <iostream>
#include <vector>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 在排序数组中查找数字
 *
 * 描述:
 * 统计一个数字在排序数组中出现的次数
 *
 * 思路:
 * 基于二分法的查找
 * 1. 如果中间数等于目标数，计数增加，但是两遍还要继续深入
 * 2. 如果中间数小于目标数，计数不变，往右边深入
 * 3. else, 往左边深入
 *
 * 特别需要注意，中间数判断过后，不能再取，即取开区间
*/

class Solution {
public:
    void binaryCount(vector<int> data, int p, int r, int k) {
        if (p <= r) {
            int q = (p + r) / 2;
            if (data[q] == k) {
                ++cnt;
                binaryCount(data, p, q - 1, k);
                binaryCount(data, q + 1, r, k);
            } else if (data[q] > k) {
                binaryCount(data, p, q - 1, k);
            } else binaryCount(data, q + 1, r, k);
        }
    }
    int GetNumberOfK(vector<int> data ,int k) {
        if (!data.size()) return 0;
        binaryCount(data, 0, data.size() - 1, k);
        return cnt;
    }
private:
    int cnt = 0;
};
int main() {
    vector<int> a = {3,1};
    Solution s;
    cout << s.GetNumberOfK(a, 1) << endl;
}