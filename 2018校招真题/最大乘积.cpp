/*
 * 来源: 2018 校招真题
 * 题目: 最大乘积
 *
 * 题目描述:
 * 给定一个无序数组，包含正数、负数和0，要求从中找出3个数的乘积，使得乘积最大，要求时间复杂度：O(n)，空间复杂度：O(1)
 *
 * 输入描述:
 * 无序整数数组A[n]
 *
 * 输出描述:
 * 满足条件的最大乘积
 *
 * 示例1:
 * 输入:
 * 3 4 1 2
 *
 * 输出:
 * 24
 *
 * 思路:
 * 找到 最小的两项 以及 最大的三项
 */

#include <iostream>
using namespace std;

int main() {
    int n, num;
    cin >> n;
    long long min_1st = 1, min_2nd = 1; // 最小的两项
    long long max_1st = -1, max_2nd = -1, max_3rd = -1; // 最大的三项
    long long ans;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        if (num < min_1st) {
            min_2nd = min_1st;
            min_1st = num;
        }
        else if (num < min_2nd) min_2nd = num;
        if (num > max_1st) {
            max_3rd = max_2nd;
            max_2nd = max_1st;
            max_1st = num;
        }
        else if (num > max_2nd) {
            max_3rd = max_2nd;
            max_2nd = num;
        }
        else if (num > max_3rd) max_3rd = num;
    }
    ans = max_1st * max(max_2nd * max_3rd, min_1st * min_2nd);
    cout << ans << endl;
    return 0;
}
