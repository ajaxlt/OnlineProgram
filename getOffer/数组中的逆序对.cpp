#include <iostream>
#include <vector>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 数组中的逆序对
 *
 * 描述:
 * 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对
 * 输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出
 * 即输出 P%1000000007
 *
 * 思路:
 * 利用归并排序思想
 * 首先利用split函数对数组分解至底
 * 对于某个合并结点, 数组分为 p, q, r
 * p ~ q 有序, q + 1 ~ r 有序
 * 三个指针, p1, p2, p3 分别指向左边的尾, 右边的尾, 原尾
 * 若左边当前小于右边当前, 右边下落
 * 否则, 左边下落, 且cnt 增加 右边所剩元素总数
 * 直到某一边全部下落，然后对未下落的一边进行善后
 *
 * 思路总结就是在归并的同时，进行记录
*/

class Solution {
public:
    void mergeAndCount(vector<int>& data, int p, int q, int r) {
        const int llen = q - p + 1;
        const int rlen = r - q;
        vector<int> left(llen);
        vector<int> right(rlen);
        for (int i = 0; i < llen; ++i) left[i] = data[p + i];
        for (int i = 0; i < rlen; ++i) right[i] = data[q + 1 + i];
        int p1 = llen - 1, p2 = rlen - 1, p3 = r;
        while(p1 >= 0 && p2 >= 0) {
            if (left[p1] > right[p2]) { // 左边大
                cnt += (p2 + 1);
                data[p3] = left[p1];
                --p1;
            }
            else { //右边大
                data[p3] = right[p2];
                --p2;
            }
            --p3;
        }
        while(p1 >= 0) data[p3--] = left[p1--];
        while(p2 >= 0) data[p3--] = right[p2--];
    }
    void split(vector<int>& data, int p, int r) {
        if (p < r) {
            int q = (p + r) >> 1;
            split(data, p, q);
            split(data, q + 1, r);
            mergeAndCount(data, p, q, r);
        }
    }
    int InversePairs(vector<int> data) {
        split(data, 0, data.size() - 1);
        return cnt;
    }

private:
    int cnt = 0;
};
int main() {
    vector<int> a = {1,2};
    Solution s;
    cout << s.InversePairs(a) << endl;
}