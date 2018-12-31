#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 第k个排列(Permutation Sequence)
 *
 * 描述:
 * 给出集合 [1,2,3,…,n], 其所有元素共有 n! 种排列
 *
 * 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 *
 * 给定 n 和 k，返回第 k 个排列
 *
 * 思路:
 * 我们从第一个数字出发, 总共 n 种数字打头，每种内部有 (n - 1)  个排列
 * 命 j = n
 * 1. 如果 j = n!, 将 j 以及其之后的元素倒序打印
 * 2. 否则，为当前位找到合适的数字
 * 3. --j
*/

class Solution {
public:
    int getK(const vector<bool>& use, int n, int k) {
        int j = 0, i = 1;
        for (; i <= n; ++i) {
            if (!use[i] && ++j == k) break;
        }
        return i;
    }
    string getPermutation(int n, int k) {
        vector<bool> use(n + 1, false);
        string ans = "";
        int j = n;
        while(k != fact[j - 1] * j) {
            int curTotal = fact[j - 1];
            int cnt = (k - 1) / curTotal;
            int next = getK(use, n, cnt + 1);
            ans += to_string(next);
            use[next] = true;
            k -= cnt * curTotal;
            --j;
        }
        for (int i = n; i > 0; --i) {
            if (!use[i]) ans += to_string(i);
        }
        return ans;
    }
private:
    int fact[10] = {
            1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880
    };
};
