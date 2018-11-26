#include <iostream>
#include <vector>
#include <string.h>
#include <map>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 最小的k个数
 *
 * 描述:
 * 输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4
 *
 * 思路：
 * 基于小顶堆的堆排序
 *
*/
class Solution {
public:
    int left(int i){
        return (i << 1) + 1;
    }
    int right(int i){
        return left(i) + 1;
    }
    void minHeapify(vector<int>& a, int i, int heapSize) {
        int lchd = left(i), rchd = right(i), smallest = i;
        if (lchd < heapSize && a[lchd] < a[i]) smallest = lchd;
        if (rchd < heapSize && a[rchd] < a[smallest]) smallest = rchd;
        if (smallest != i) {
            swap(a[i], a[smallest]);
            minHeapify(a, smallest, heapSize);
        }
    }
    int buildMinHeap(vector<int>& a) {
        int heapSize = a.size();
        for (int i = (heapSize >> 1) - 1; i >= 0; --i) minHeapify(a, i, heapSize);
        return heapSize;
    }
    vector<int> GetLeastNumbers_Solution(vector<int> a, int k) {
        if (k <= 0 || k > a.size() || a.size() == 0) return {}; //滤除垃圾边界
        if (k == a.size()) { // 等价于排序
            sort(a.begin(), a.end());
            return a;
        }
        vector<int> rlt;
        int heapSize = buildMinHeap(a);
        for (int i = a.size() - 1; i >= a.size() - k; --i) {
            rlt.push_back(a[0]);
            swap(a[i], a[0]);
            --heapSize;
            minHeapify(a, 0, heapSize);
        }
        return rlt;
    }
};