#include <iostream>
#include <vector>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 斐波那契数列
 *
 * 描述: Fibonacci(n) = ?
 *
 * 思路:
 * {{f(n), f(n - 1)}, {f(n - 1), f(n - 2)}} = {{1, 1},{1, 0}} ^ (n - 1)
 * 因此，可以用矩阵的幂来求解
 * 同时还能利用分治法
*/

vector<vector<int>> ori = {{1, 1}, {1, 0}};
class Solution {
public:
    vector<vector<int>> calMul(vector<vector<int>> tmp1, vector<vector<int>> tmp2) {
        vector<vector<int>> rlt = {{0, 0}, {0, 0}};
        rlt[0][0] = tmp1[0][0] * tmp2[0][0] + tmp1[0][1] * tmp2[1][0];
        rlt[0][1] = tmp1[0][0] * tmp2[0][1] + tmp1[0][1] * tmp2[1][1];
        rlt[1][0] = tmp1[1][0] * tmp2[0][0] + tmp1[1][1] * tmp2[0][1];
        rlt[1][1] = tmp1[1][0] * tmp2[0][1] + tmp1[1][1] * tmp2[1][1];
        return rlt;
    }
    vector<vector<int>> calMatPow(vector<vector<int>> tmp, int n) {
        if (n <= 1) return tmp;
        else {
            vector<vector<int>> b_tmp = calMatPow(tmp, n / 2);
            if (n % 2 == 0) return calMul(b_tmp, b_tmp);
            else {
                return calMul(ori, calMul(b_tmp, b_tmp));
            }
        }

    }
    int Fibonacci(int n){
        if (n == 0) return 0;
        return calMatPow(ori, n - 1)[0][0];
    }
};
