#include <iostream>
#include <string.h>
#include <string>
#include <vector>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 扑克牌顺子
 *
 * 描述:
 * 见原题
 *
 * 思路:
 * 简单题
 *
*/
class Solution {
public:
    inline bool isLegal(int i) {
        if (i < 0 || i >= up || use[i]) return false;
        else {
            use[i] = true;
            return true;
        }
    }
    bool IsContinuous(vector<int> numbers) {
        if (numbers.empty()) return 0;
        memset(use, false, sizeof(use));
        int Max = -1, Min = up;
        for (int i = 0; i < numbers.size(); ++i) {
            if (numbers[i] == 0) continue;
            if (!isLegal(numbers[i])) return false;
            Max = max(Max, numbers[i]);
            Min = min(Min, numbers[i]);
        }
        return Max - Min < maxLen;
    }
private:
    static const int up = 14;
    static const int maxLen = 5;
    bool use[up];
};
int main() {
    Solution s;
    cout << s.IsContinuous({1,2,3,0,6}) << endl;
}