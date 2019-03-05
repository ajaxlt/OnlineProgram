/*
 * 来源: 2018 校招真题
 * 题目: 六一儿童节
 *
 * 题目描述:
 * 六一儿童节，老师带了很多好吃的巧克力到幼儿园。每块巧克力j的重量为w[j]，对于每个小朋友i，当他分到的巧克力大小达到h[i] (即w[j]>=h[i])，他才会上去表演节目
 * 老师的目标是将巧克力分发给孩子们，使得最多的小孩上台表演
 * 可以保证每个w[i]> 0，且不能将多块巧克力分给一个孩子或将一块分给多个孩子
 *
 * 思路:
 * 贪心，将价值较大的巧克力分给阈值较大的孩子
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> h(n); // 阈值
    for (int i = 0; i < n; ++i) cin >> h[i];
    cin >> m;
    vector<int> w(m); // 巧克力权值
    for (int j = 0; j < m; ++j) cin >> w[j];

    sort(h.begin(), h.end());
    sort(w.begin(), w.end());
    int i = n - 1, j = m - 1;
    int ans = 0;
    while(i >= 0 && j >= 0) {
        for (; i >= 0 && h[i] > w[j]; --i);
        if (i < 0) break;
        ++ans, --i, --j;

    }
    cout << ans << endl;
    return 0;
}
