#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 天际线问题(The Skyline Problem)
 *
 * 描述:
 * 见原题 https://leetcode-cn.com/problems/the-skyline-problem/
 *
 * 思路:
 * 维护线段树
 */

bool cmp (const vector<int>& lhs, const vector<int>& rhs) {
    return lhs[0] == rhs[0] ? lhs[1] > rhs[1] : lhs[0] < rhs[0];
}
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings){
        int len = buildings.size();
        if (len == 0) return {};
        vector<vector<int>> height(2 * len);
        vector<pair<int, int>> ans;
        // left 存放左顶点, right 存放右顶点
        for (int i = 0; i < len; ++i) {
            height[2 * i] = {buildings[i][0], buildings[i][2]};
            height[2 * i + 1] = {buildings[i][1], -buildings[i][2]};
        }
        sort(height.begin(), height.end(), cmp);

        map<int, int, greater<int>> S;
        S[0] = 1;//加入地平线;

        int prev = 0;
        for (auto h : height) {
            if (h[1] > 0) ++S[h[1]];
            else {
                if(--S[-h[1]] == 0)
                    S.erase(-h[1]);
            }

            int cur = S.begin() -> first;
            //cout << cur << endl;
            if (prev != cur) {
                ans.push_back(make_pair(h[0], cur));
                prev = cur;
            }
        }
        return ans;
    }
};