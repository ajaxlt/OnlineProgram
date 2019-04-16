#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 加油站(Gas Station)
 *
 * 描述:
 * 在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升
 * 你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空
 * 如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1
 *
 * 说明:
 * 如果题目有解，该答案即为唯一答案
 * 输入数组均为非空数组，且长度相同
 * 输入数组中的元素均为非负数
 *
 * 思路:
 * 模拟题
 */

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        for (int i = 0; i < len; ++i) {
            int j = i;
            int g = gas[j];
            while (g >= cost[j]) {
                g += (-cost[j] + gas[(j + 1) % len]);
                j = (j + 1) % len;
                if (j == i) return j;
            }
        }
        return -1;
    }
};