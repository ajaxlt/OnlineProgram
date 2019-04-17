#include <iostream>
#include <string>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 整数转罗马数字(Integer to Roman)
 *
 * 描述:
 * 罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。
 * 字符          数值
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
 * 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV
 * 数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX
 * 这个特殊的规则只适用于以下六种情况：
 * I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
 * X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
 * C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
 *
 * 给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。
 *
 * 思路:
 * 从大的罗马数字开始，进行遍历即可
 *
 * 主要问题是存在特别组合 IV, IX, XL, XC, CD, CM
 * 需要找到每两者的映射
*/

class Solution {
public:
    string intToRoman(int num) const {
        string roman = "";
        for (int i = n - 1; i >= 0 && num > 0; --i) {
            while (num - int7[i] >= 0) {
                roman.push_back(char7[i]);
                num -= int7[i];
            }
            int j = (i - 1) / 2 * 2; // 映射关系
            if (i != 0 && int7[i] - num <= int7[j]) {
                roman.push_back(char7[j]);
                roman.push_back(char7[i]);
                num -= (int7[i] - int7[j]);
            }
        }
        return roman;
    }
private:
    static const int n = 7;
    const int int7[n] = {1, 5, 10, 50, 100, 500, 1000};
    const char char7[n] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
};