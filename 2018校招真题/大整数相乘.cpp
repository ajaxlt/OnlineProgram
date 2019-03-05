/*
 * 来源: 2018 校招真题
 * 题目: 大整数相乘
 *
 * 题目描述:
 * 大数乘法
 *
 * 思路:
 * 1. 创建一个整形数组 c 用于存放相乘后每一位的结果, 不进位
 * 2. 从后往前遍历数组 c, 逐级进位
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    const int len1 = a.size(), len2 = b.size(), len3 = len1 + len2;
    vector<int> c(len3, 0);
    for (int i = 0; i < len1; ++i) {
        for (int j = 0; j < len2; ++j) {
            c[i + j + 1] += (a[i] - '0') * (b[j] - '0');
        }
    }
    int carry = 0;
    string ans = "";
    for (int i = len3 - 1; i > 0; --i) {
        int cur = c[i] + carry;
        c[i] = cur % 10;
        carry = cur / 10;
        ans = to_string(c[i]) + ans;
    }
    if (carry) ans = to_string(carry) + ans;
    cout << ans << endl;
    return 0;
}
