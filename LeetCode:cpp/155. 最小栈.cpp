#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/*
 * 来源: LeetCode
 * 题目: 最小栈(Min Stack)
 *
 * 描述:
 * 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈
 * push(x) -- 将元素 x 推入栈中
 * pop() -- 删除栈顶的元素
 * top() -- 获取栈顶元素
 * getMin() -- 检索栈中的最小元素
 *
 * 思路:
 * 两个栈
 */



class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        stk1.push(x);
        if (stk2.empty() || x < stk2.top()) stk2.push(x);
        else stk2.push(stk2.top());
    }

    void pop() {
        if (!stk1.empty()) {
            stk1.pop();
            stk2.pop();
        }
    }

    int top() {
        return stk1.top();
    }

    int getMin() {
        return stk2.top();
    }
private:
    stack<int> stk1, stk2;
};