/*
 * 来源: 2018 校招真题
 * 题目: 疯狂队列
 *
 * 题目描述:
 * 小易老师是非常严厉的,它会要求所有学生在进入教室前都排成一列,并且他要求学生按照身高不递减的顺序排列
 * 有一次,n个学生在列队的时候,小易老师正好去卫生间了
 * 学生们终于有机会反击了,于是学生们决定来一次疯狂的队列,他们定义一个队列的疯狂值为每对相邻排列学生身高差的绝对值总和
 * 由于按照身高顺序排列的队列的疯狂值是最小的,他们当然决定按照疯狂值最大的顺序来进行列队。
 * 在给出n个学生的身高,请计算出这些学生列队的最大可能的疯狂值。小易老师回来一定会气得半死
 *
 * 输入描述:
 * 输入包括两行,第一行一个整数n(1 ≤ n ≤ 50),表示学生的人数
 * 第二行为n个整数h[i](1 ≤ h[i] ≤ 1000),表示每个学生的身高
 *
 * 输出描述:
 * 输出一个整数,表示n个学生列队可以获得的最大的疯狂值
 *
 * 如样例所示:
 * 当队列排列顺序是: 25-10-40-5-25, 身高差绝对值的总和为15+30+35+20=100
 * 这是最大的疯狂值了
 *
 * 示例1:
 * 输入:
 * 5
 * 5 10 25 40 25
 *
 * 输出:
 * 100
 *
 * 思路:
 * 维护队列的左右端点
 *
 * 首先，将数组排序，然后将最大值与最小值分别赋给队列的左，右端点
 * 然后取数组的第 i 小值 和 第 i 大值 "交替" 地放到队列的左，右端点
 * 并不断更新 ans
 *
 * 如果队列长度为偶数，则最后剩下 0 个，可以直接输出 ans
 * 如果队列长度为奇数，则最后剩下 1 个，将之与左右端点比较而决定究竟放在左端点还是右端点
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Crazy(vector<int>& tmp, int n) {
    if (n == 1) return 0;
    int lhs = tmp[0], rhs = tmp[n - 1];
    int ans = rhs - lhs;
    int i = 1, j = n - 2;
    bool k = false;
    while(i < j) {
        if (!k) {
            ans += rhs - tmp[i];
            ans += tmp[j] - lhs;
            rhs = tmp[i++];
            lhs = tmp[j--];
        }
        else {
            ans += lhs - tmp[i];
            ans += tmp[j] - rhs;
            rhs = tmp[j--];
            lhs = tmp[i++];
        }
        k = !k;
    }
    if (i == j) ans += max(abs(lhs - tmp[i]), abs(rhs - tmp[j]));
    return ans;
}
int main () {
    int n;
    cin >> n;
    vector<int> tmp(n);
    for (int i = 0; i < n; ++i) cin >> tmp[i];
    sort(tmp.begin(), tmp.end());
    cout << Crazy(tmp, n) << endl;
    return 0;
}
