#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 地下城游戏(Dungeon Game)
 *
 * 描述:
 * 一些恶魔抓住了公主（P）并将她关在了地下城的右下角。地下城是由 M x N 个房间组成的二维网格
 * 我们英勇的骑士（K）最初被安置在左上角的房间里，他必须穿过地下城并通过对抗恶魔来拯救公主
 * 骑士的初始健康点数为一个正整数。如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡
 * 有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数（若房间里的值为负整数，则表示骑士将损失健康点数
 * 其他房间要么是空的（房间里的值为 0），要么包含增加骑士健康点数的魔法球（若房间里的值为正整数，则表示骑士将增加健康点数）
 * 为了尽快到达公主，骑士决定每次只向右或向下移动一步。
 *
 *
 * 示例:
 * 例如，考虑到如下布局的地下城，如果骑士遵循最佳路径 右 -> 右 -> 下 -> 下，则骑士的初始健康点数至少为 7
 * -2 (K)	-3	3
 * -5	   -10	1
 * 10	    30	-5 (P)
 *
 * 思路:
 * 针对于单向(只能向下或者向右)的图问题，可以考虑 dp
 * 反向 dp， 从终点出发向起点迭代
*/
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size(), columns = dungeon[0].size();
        if (rows == 0 || columns == 0) return 0;

        vector<vector<int>> dp(rows, vector<int>(columns));

        // 初始化终点
        dp[rows - 1][columns - 1] = max(1, 1 - dungeon[rows - 1][columns - 1]);

        // 初始化右边界
        for (int i = rows - 2; i >= 0; --i) {
            dp[i][columns - 1] =
                    max(1, dp[i + 1][columns - 1] - dungeon[i][columns - 1]);
        }
        // 初始化下边界
        for (int j = columns - 2; j >= 0; --j) {
            dp[rows - 1][j] =
                    max(1, dp[rows - 1][j + 1] - dungeon[rows - 1][j]);
        }

        // dp
        for (int i = rows - 2; i >= 0; --i) {
            for (int j = columns - 2; j >= 0; --j) {
                int tar = min(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = max(1, tar - dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};
