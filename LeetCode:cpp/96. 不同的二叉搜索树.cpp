#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 不同的二叉搜索树(Unique Binary Search Trees)
 *
 * 描述:
 * 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
 *
 * 思路:
 * 卡塔兰数
 *
 * 以 i 为根节点，则左边只能取 0 .. i - 1，右边只能取i + 1 .. n
 *
 * 因此 dp[i] = sum(dp[j] * dp[i - j -1]), 0 <= j < i
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};