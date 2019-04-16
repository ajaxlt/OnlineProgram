#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: Excel表列名称(Excel Sheet Column Title)
 *
 * 描述:
 * 给定一个正整数，返回它在 Excel 表中相对应的列名称。
 * 例如，

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB
    ...
 * 示例 1:
 * 输入: 1
 * 输出: "A"
 *
 * 示例 2:
 * 输入: 28
 * 输出: "AB"
 *
 * 示例 3:
 * 输入: 701
 * 输出: "ZY"
 *
 * 思路:
 * 10进制转26进制，但是 0 是缺省的，最小是 1，因此转换时每次要让待转换数 -1
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        int i = 0, j = len - 1;
        while(i < j) {
            if (numbers[i] + numbers[j] == target) return {i + 1, j + 1};
            else if (numbers[i] + numbers[j] < target) ++i;
            else --j;
        }
        return {};
    }
};