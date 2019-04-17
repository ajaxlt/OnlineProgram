#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 比较版本号(Compare Version Numbers)
 *
 * 描述:
 * 比较两个版本号 version1 和 version2
 *
 * 示例 1:
 * 输入: version1 = "0.1", version2 = "1.1"
 * 输出: -1
 *
 * 示例 2:
 * 输入: version1 = "1.0.1", version2 = "1"
 * 输出: 1
 *
 * 示例 3:
 * 输入: version1 = "7.5.2.4", version2 = "7.5.3"
 * 输出: -1
 *
 * 示例 4：
 * 输入：version1 = "1.01", version2 = "1.001"
 * 输出：0
 * 解释：忽略前导零，“01” 和 “001” 表示相同的数字 “1”
 *
 * 示例 5：
 * 输入：version1 = "1.0", version2 = "1.0.0"
 * 输出：0
 * 解释：version1 没有第三级修订号，这意味着它的第三级修订号默认为 “0”。
 *
 * 思路:
 * 字符串比较
 */

class Solution {
public:
    void trans(string& s, vector<int>& v) {
        s += ".";
        int i = 0;
        int cur = 0;
        bool pre = true;

        while(i < s.size()) {
            if (s[i] == '0' && pre) {
                ++i;
                continue;
            }
            else pre = false;

            if (s[i] == '.') {
                v.push_back(cur);
                cur = 0;
                pre = true;
            }
            else cur = cur * 10 + (s[i] - '0');
            ++i;
        }
    }
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        trans(version1, v1);
        trans(version2, v2);
        int len = max(v1.size(), v2.size());

        for (int i = 0; i < len; ++i) {
            int a = i < v1.size() ? v1[i] : 0;
            int b = i < v2.size() ? v2[i] : 0;
            if (a < b) return -1;
            if (a > b) return 1;
        }
        return 0;
    }
};
