#include <iostream>
#include <vector>
#include <set>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 构建乘积数组
 *
 * 描述:
 * 给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1]
 * 其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]
 * 注: 不能使用除法
 *
 * 思路:
 * B[i] =  (A[i] 中 不含 i 这个元素的所有乘积)
 *
 * 令初始B[0] = 1
 *
 * 根据原书313所示插图,
 * 先算下三角，再返回乘上 上三角
*/

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        if (A.empty()) return {};
        const int len = A.size();
        vector<int> B(len);
        B[0] = 1;
        for (int i = 1; i < len; ++i) B[i] = B[i - 1] * A[i - 1];
        int tmp = 1;
        for (int i = len - 2; i >= 0; --i) {
            tmp *= A[i + 1];
            B[i] *= tmp;
        }
        return B;
    }
};
