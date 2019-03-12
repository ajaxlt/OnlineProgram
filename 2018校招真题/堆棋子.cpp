/*
 * 来源: 2018 校招真题
 * 题目: 堆棋子
 *
 * 题目描述:
 * 小易将n个棋子摆放在一张无限大的棋盘上
 * 第i个棋子放在第x[i]行y[i]列。同一个格子允许放置多个棋子
 * 每一次操作小易可以把一个棋子拿起并将其移动到原格子的上、下、左、右的任意一个格子中
 * 小易想知道要让棋盘上出现有一个格子中至少有i(1 ≤ i ≤ n)个棋子所需要的最少操作次数
 *
 * 思路:
 *
 * 假定总共有 n 个点，则目标点可能是(x_i, y_i), (0 <= i, j <= n)
 * 即，可能是 n 中所有的横坐标, 纵坐标的组合
 * 遍历所有可能的目标点，计算 n 个点与之的曼哈顿距离，并排序
 *
 * 这样可以得到 n^2 个 n 维的数组
 * 然后枚举棋子数，比如计算棋子为 i 时的最优解
 * 则找到 n^2 个数组中 前 i 项加起来最小的即可
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Node{
    int x, y;
}node[55];

vector<vector<int>> store;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> node[i].x;
    for (int i = 0; i < n; ++i) cin >> node[i].y;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // 枚举所有可能作为终点的点
            // node[i].x, node[j].y
            // 计算所有点
            // node[k].x, node[k].y
            // 与该点的曼哈顿距离
            vector<int> tmp(n);
            for (int k = 0; k < n; ++k) {
                int dist = abs(node[i].x - node[k].x) + abs(node[j].y - node[k].y);
                tmp[k] = dist;
            }
            sort(tmp.begin(), tmp.end());
            store.push_back(tmp);
        }
    }


    for (int i = 0; i < n; ++i) { // 枚举棋子数
        int Min = INT32_MAX;
        for (int j = 0; j < store.size(); ++j) { // 枚举tmp
            int cur = 0;
            for (int k = 0; k <= i; ++k) { // 枚举和
                cur += store[j][k];
            }
            Min = min(Min, cur);
        }
        cout << Min;
        if (i == n - 1) cout << endl;
        else cout << " ";
    }
    return 0;
}
