/*
 * 来源: 2018 校招真题
 * 题目: 迷宫寻路
 *
 * 题目描述:
 * 假设一个探险家被困在了地底的迷宫之中，要从当前位置开始找到一条通往迷宫出口的路径
 * 迷宫可以用一个二维矩阵组成，有的部分是墙，有的部分是路
 * 迷宫之中有的路上还有门，每扇门都在迷宫的某个地方有与之匹配的钥匙，只有先拿到钥匙才能打开门
 * 请设计一个算法，帮助探险家找到脱困的最短路径
 * 如前所述，迷宫是通过一个二维矩阵表示的，每个元素的值的含义如下 0-墙，1-路，2-探险家的起始位置，3-迷宫的出口，大写字母-门，小写字母-对应大写字母所代表的门的钥匙
 *
 * 输入描述:
 * 迷宫的地图，用二维矩阵表示。第一行是表示矩阵的行数和列数M和N
 * 后面的M行是矩阵的数据，每一行对应与矩阵的一行（中间没有空格）。M和N都不超过100, 门不超过10扇。
 *
 * 输出描述:
 * 路径的长度，是一个整数
 *
 * 示例1
 * 输入:
 * 5 5
 *
 * 0 2 1 1 1
 * 0 1 a 0 A
 * 0 1 0 0 3
 * 0 1 0 0 1
 * 0 1 1 1 1
 *
 * 输出:
 * 7
 *
 * 思路:
 * 相对于普通的bfs，本题多了一个"钥匙"的条件
 * 因此， vis 数组应该为 "钥匙" 增加一维，而成一个三维的数组
 * 当前佩戴的钥匙可以用 二进制 表示， 因钥匙不多于 10 个，因此可以用一个 10 位长度的二进制表示
 * 每一位是否为 1 可以表示是否拥有该钥匙
 */

#include<iostream>
#include<string.h>
#include<queue>

using namespace std;
int rows, columns;
char maze[110][110]; // 迷宫
bool status[110][110][1100]; // 状态，由 x, y 以及携带的钥匙状态决定
// 由二进制表示钥匙状态
int shift[4][2] = {1, 0, -1, 0, 0 ,1, 0, -1}; // 四个方向
int bfs(int beg_i, int beg_j);

struct node {
    int x, y, key, stp;
    node(int _x, int _y, int _key, int _stp)
            : x(_x), y(_y), key(_key), stp(_stp) {}
};

int main() {
    cin >> rows >> columns;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < columns; ++j)
            cin >> maze[i][j];

    memset(status, false, sizeof(status)); // 所有状态初始化未访问
    int flag = false;
    for (int i = 0; i < rows && !flag; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (maze[i][j] == '2') {
                flag = true;
                status[i][j][0] = true;
                cout << bfs(i, j) << endl;
                break;
            }
        }
    }
    return 0;
}
int bfs(int beg_i, int beg_j) {
    queue<node> Q;
    Q.push(node(beg_i, beg_j, 0, 0));
    while (!Q.empty()) {
        node cur = Q.front();
        Q.pop();
        for (int g = 0; g < 4; ++g) {
            int nx = cur.x + shift[g][0], ny = cur.y + shift[g][1];
            if (nx >= rows || nx < 0 || ny >= columns || ny < 0 ||
                maze[nx][ny] == '0') continue;
            if (maze[nx][ny] == '3')
                return cur.stp + 1;
            int key = cur.key;
            // 如果当前点是钥匙，准备更新钥匙状态
            if ('a' <= maze[nx][ny] && maze[nx][ny] <= 'z')
                key = key | (1 << (maze[nx][ny] - 'a'));
            // 如果当前点是门，且没有钥匙的话
            if ('A' <= maze[nx][ny] && maze[nx][ny] <= 'Z' &&
                (key & (1 << (maze[nx][ny] - 'A'))) == 0)
                continue;

            if (!status[nx][ny][key]) {
                status[nx][ny][key] = true;
                Q.push(node(nx, ny, key, cur.stp + 1));
                //cout << nx << ", " << ny << endl;
            }
        }
    }
    return -1;
}
