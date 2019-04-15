#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 直线上最多的点数(Max Points on a Line)
 *
 * 描述:
 * 给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上
 *
 * 示例 1:
 * 输入: [[1,1],[2,2],[3,3]]
 * 输出: 3
 * 解释:
 * ^
 * |
 * |        o
 * |     o
 * |  o
 * +------------->
 * 0  1  2  3  4
 *
 * 示例 2:
 * 输入: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 * 输出: 4
 * 解释:
 * ^
 * |
 * |  o
 * |     o        o
 * |        o
 * |  o        o
 * +------------------->
 * 0  1  2  3  4  5  6
 *
 * 思路:
 * 根据斜率，可以判断点是不是在同一直线上: 比如，A, B, C 三个点
 * A 与 B 连线的斜率等于A 与 C 连线的斜率，那么A, B, C 三点一线
 *
 * 斜率的存放方式应该用分数，即两个整数相除，当然，还需要做约分处理
 * 另外，还应该额外考虑点重复的情况
 */


struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

bool cmp (const Point& lhs, const Point& rhs) {
    return lhs.x == rhs.x ? lhs.y < rhs.y : lhs.x < rhs.x;
}
class Solution {
public:
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
    int maxPoints(vector<Point>& points) {
        int len = points.size();
        if (len == 0) return 0;
        int ans = 1;
        sort(points.begin(), points.end(), cmp);// 排序是为了让重复的点先靠在一起
        for (int i = 0; i < points.size(); ++i) {
            map<pair<int, int>, int> m; //存储斜率
            // pair<int, int> 分别存放斜率的分子和分母
            int repeat = 1; // 判别重复的点
            for (int j = i + 1; j < points.size(); ++j) {
                if (points[i].x != points[j].x || points[i].y != points[j].y) {
                    int dx = points[j].x - points[i].x;
                    int dy = points[j].y - points[i].y;
                    int d = gcd(dx, dy); // 最大公约数，用于约分
                    ans = max(ans, ++m[{dx / d, dy / d}] + repeat);
                }
                else ans = max(ans, ++repeat);
            }
        }
        return ans;
    }
};
