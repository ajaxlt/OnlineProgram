#include <iostream>
#include <string.h>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 孩子们的游戏(圆圈中最后剩下的数)
 *
 * 描述:
 * 约瑟夫环（约瑟夫问题）
 * 已知n个人（以编号0，1，1...n - 1分别表示）围坐在一张圆桌周围
 * 从编号为0的人开始报数，数到m - 1的那个人出列
 * 他的下一个人又从0开始报数，数到m的那个人又出列
 * 依此规律重复下去，问剩下的最后一人
 *
 * 思路:
 * 模拟法
 *
*/
class Solution {
public:
    inline int nextChild(int curChild, int n){
        return (curChild == n - 1) ? 0 : curChild + 1;
    }
    int LastRemaining_Solution(int n, int m)
    {
        if(n <= 0 || m <= 0) return -1; //异常控制
        bool use[n];
        int numOfuse = n, curNum = 0, curChild = 0;
        //numOfuse -> 当前剩下的人数
        //curNum -> 当前报的数
        //curChild -> 当前报数的小孩
        memset(use, true, sizeof(use));
        while(numOfuse != 0) {
            if (use[curChild]) {
                ++curNum;
                if (curNum == m) {
                    curNum = 0;
                    use[curChild] = false;
                    --numOfuse;
                    continue;
                }
            }
            curChild = nextChild(curChild, n);
        }
        return curChild;
    }
};
int main(){
    Solution s;
    cout << s.LastRemaining_Solution(10, 1) << endl;
}