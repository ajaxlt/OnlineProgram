#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 把数组排成最小的数
 *
 * 描述:
 * 输入一个正整数数组，把数组里所有数字拼接起来排成一个数
 * 打印能拼接出的所有数字中最小的一个。例如，输入数组{3, 32, 321}
 * 则打印出这3个数字能排成的最小数字为321323
 *
 * 思路：
 * 先将整数数组转换成字符串数组，自定义排序函数
 * return a+ b > b + a
 * 有效的排序需要从3个角度去证明:
 * 自反性，对称性以及传递性
*/
bool cmp(string a, string b) {
    return a + b < b + a;
}
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> strNums;
        for (int i : numbers) strNums.push_back(to_string(i));
        sort(strNums.begin(), strNums.end(), cmp);
        string rlt = "";
        for (string s : strNums) rlt += s;
        return rlt;
    }
};
int main() {
    vector<int > num = {3, 32, 321};
    Solution s;
    cout << s.PrintMinNumber(num) << endl;
}
