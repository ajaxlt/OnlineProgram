#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 卡牌分组(X of a Kind in a Deck of Cards)
 *
 * 描述:
 * 给定一副牌，每张牌上都写着一个整数。
 * 此时，你需要选定一个数字 X，使我们可以将整副牌按下述规则分成 1 组或更多组：
 * 每组都有 X 张牌。
 * 组内所有的牌上都写着相同的整数。
 * 仅当你可选的 X >= 2 时返回 true。
 *
 * 示例 1：
 * 输入：[1,2,3,4,4,3,2,1]
 * 输出：true
 * 解释：可行的分组是 [1,1]，[2,2]，[3,3]，[4,4]
 *
 * 示例 2：
 * 输入：[1,1,1,2,2,2,3,3]
 * 输出：false
 * 解释：没有满足要求的分组。
 *
 * 示例 3：
 * 输入：[1]
 * 输出：false
 * 解释：没有满足要求的分组。
 *
 * 示例 4：
 * 输入：[1,1]
 * 输出：true
 * 解释：可行的分组是 [1,1]
 *
 * 示例 5：
 * 输入：[1,1,2,2,2,2]
 * 输出：true
 * 解释：可行的分组是 [1,1]，[2,2]，[2,2]
 *
 * 思路:
 * 先计数，再解最大公约数
 */

class Solution {
public:
    inline int gcd( int a, int b)
    {
        return b > 0 ? gcd(b, a % b) : a;
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        int len = deck.size();
        if (len < 2) return false;

        const int m = 10010;
        vector<int> cnt(m, 0);
        for (int i = 0; i < deck.size(); ++i) ++cnt[deck[i]];
        int n = cnt[deck[0]];
        for (int i = 1; i < deck.size(); ) {
            if (cnt[deck[i]]) {
                int g = gcd(n, cnt[deck[i]]); // 最大公约数
                if (g == 1) return false;
                else n = g;
            }
            while(deck[i] == deck[++i]); // 去重
        }
        return true;
    }
};