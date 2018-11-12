#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 两个栈实现队列
 *
 * 描述: 用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型
 *
 * 思路:
 * 队列 -> 先进先出
 * 因此我们只要保证 push 函数使的元素排在栈底就可以了
 * stack2作为桥梁
 * push之前，把stack1里的全部“倾倒”给stack2
 * 将新元素push入stack1，再将stack2里的元素“倾倒”回来即可
 *
*/

class Solution
{
public:
    void push(int node) {
        while(!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        stack1.push(node);
        while(!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
    }

    int pop() {
        if (stack1.empty()) throw("queue is empty");
        int rlt = stack1.top();
        stack1.pop();
        return rlt;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};