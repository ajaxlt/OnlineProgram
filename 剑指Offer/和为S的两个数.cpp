#include <iostream>
#include <vector>
#include <set>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 和为S的两个数
 *
 * 描述:
 * 输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S
 * 如果有多对数字的和等于S，输出两个数的乘积最小的
 *
 *
 * 思路:
 * 简单题，set或者map
*/

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        if (array.size() < 2) return {};
        set<int> s;
        int a = 0, b = 0, mul = INT32_MAX;
        for (int i = 0; i < array.size(); ++i) {
            int j = sum - array[i];
            if (s.count(j) && j * array[i] < mul) {
                a = j;
                b = array[i];
                mul = a * b;
            }
            s.insert(array[i]);
        }
        if (!a && !b) return {};
        else return {a, b};
    }
};