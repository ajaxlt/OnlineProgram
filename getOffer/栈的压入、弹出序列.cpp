#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 栈的压入、弹出序列
 *
 * 描述: 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序
 * 假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列
 *
 * 思路:
 * 需要2个辅助指针i, j:  i 表示当前最后一个压入元素的下标， j 表示当前遍历的弹出元素的下标
 * 以及1个辅助栈tmp，用于模拟
 * 对于 popV[j] 而言，我们需要看 tmp.top() 是否与之相等
 * 1. 相等, tmp.pop(), 继续看下一个 j
 * 2. 不相等，tmp继续push()，如果把 pushV 中的所有元素都已经push完毕了还是无法相等， 则 return false
 *
*/
class Solution {
public:
    /**
     *
     *
     * @param[in] pushV 压入的顺序
     * @param[in] popV 弹出的顺序
     * @param[in] i 最后压入的元素下标
     * @param[in] j 当前遍历的弹出元素下标
     */
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if (pushV.empty()) return popV.empty();
        int len = pushV.size(); // 操作总长度
        stack<int> tmp;
        tmp.push(pushV[0]);// 先把首元素压入
        int i = 1, j = 0;
        while(j < len) {
            while(tmp.top() != popV[j]) {
                if (i == len) return false;
                tmp.push(pushV[i++]);
            }
            ++j;
            tmp.pop();
        }
        return true;
    }
};