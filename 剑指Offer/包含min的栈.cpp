#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 包含min函数的栈
 *
 * 描述: 定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数，时间复杂度应为O(1)
 *
 * 思路:
 * 用到辅助栈，长度与数据栈相同，但是栈顶存放的是当前数据栈中的最小值
 * 因此，每次push时，如果value比当前最小值小，则将他直接推入至辅助栈，否则将辅助栈的栈顶再次推入到辅助栈
 *
*/


class Solution {
public:
    void push(int value) {
        if (data.empty() || value < help.top()){
            data.push(value);
            help.push(value);
        } else {
            data.push(value);
            help.push(help.top());
        }
    }
    void pop() {
        if (data.empty()) throw("Invalid Operation");
        data.pop();
        help.pop();
    }
    int top() {
        return data.top();
    }
    int min() {
        return help.top();
    }
private:
    stack<int> data; // 数据栈
    stack<int> help; // 辅助栈
};