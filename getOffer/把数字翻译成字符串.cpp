#include <iostream>
#include <string>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 把数字翻译成字符串
 *
 * 描述:
 * 给定一个数字，我们按照如下规则把它翻译成字符串:
 * 0 翻译成 "a"， 1 翻译成 "b" ... ， 25翻译成"z"
 * 问总共有多少种翻译方法
 *
*/

//解法1. dfs暴搜
class Solution1 {
public:
    void dfs(int i) {
        if (i == str.length()) ++cnt;
        else {
            dfs(i + 1);
            if (str[i] == '1' || str[i] == '2' && str[i + 1] <= '5')
                dfs(i + 2);
        }
    }
    int translate(int num) {
        str = to_string(num);
        dfs(0);
        return cnt;
    }
private:
    string str;
    int cnt = 0;
};

//解法2. 反向dp
class Solution2 {
public:
    // dp[i] = dp[i + 1] + a * dp[i + 2];
    // a = 1 -> i 和 i + 1两个数字在10 ~ 25之间
    // 反向dp, 从dp[len - 1]开始
    int translate(int num) {
        string str = to_string(num);
        const size_t len = str.size();
        if (len < 2) return len;
        int dp[len];
        dp[len - 1] = 1;
        for (int i = len - 2; i >= 0; --i) {
            if (i + 2 < len && (str[i] == '1' || str[i] == '2' && str[i + 1] <= '5'))
                dp[i] = dp[i + 1] + dp[i + 2];
            else
                dp[i] = dp[i + 1];
        }
        return dp[0];
    }
};


