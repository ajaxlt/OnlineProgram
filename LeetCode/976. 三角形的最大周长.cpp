#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 三角形的最大周长(Largest Perimeter Triangle)
 *
 * 描述:
 * 给定由一些正数（代表长度）组成的数组 A，返回由其中三个长度组成的、面积不为零的三角形的最大周长
 *
 * 思路:
 * 两边之差小于第三边
 */

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        if (A.size() < 3) return 0;
        sort(A.begin(), A.end());

        for (int i = A.size() - 1; i >= 2; --i) {
            if (A[i] - A[i - 1] < A[i - 2]){
                return A[i] + A[i - 1] + A[i - 2];
            }
        }
        return 0;
    }
};