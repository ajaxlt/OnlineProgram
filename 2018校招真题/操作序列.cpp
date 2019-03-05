/*
 * 来源: 2018 校招真题
 * 题目: 操作序列
 *
 * 题目描述:
 * 小易有一个长度为n的整数序列,a_1,...,a_n。然后考虑在一个空序列b上进行n次以下操作:
 * 1、将a_i放入b序列的末尾
 * 2、逆置b序列
 *
 * 小易需要你计算输出操作n次之后的b序列
 *
 * 输入描述:
 * 输入包括两行,第一行包括一个整数n(2 ≤ n ≤ 2*10^5),即序列的长度
 * 第二行包括n个整数a_i(1 ≤ a_i ≤ 10^9),即序列a中的每个整数,以空格分割
 *
 * 输出描述:
 * 在一行中输出操作n次之后的b序列,以空格分割,行末无空格
 *
 * 示例1:
 * 输入:
 * 4
 * 1 2 3 4
 *
 * 输出:
 * 4 2 1 3
 *
 *
 * 思路:
 * 找规律，先倒序隔2输出，再正序隔2输出
 */

#include<iostream>
#include<vector>
using namespace std;
// 1
// 2 1
// 3 1 2
// 4 2 1 3
// 5 3 1 2 4
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);

    for (int k = 0; k < n; ++k) cin >> a[k];

    int i = n - 1;
    int j = 0;
    while(i >= 0) {
        b[j++] = a[i];
        i -= 2;
    }
    i = (i == -1) ? 0 : 1;
    while (i < n) {
        b[j++] = a[i];
        i += 2;
    }
    for (int k = 0; k < n; ++k) {
        cout << b[k];
        if (k != n - 1) cout << " ";
    }
    cout << endl;
    return 0;
}