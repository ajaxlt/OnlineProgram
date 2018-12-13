#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 字符流中第一个只出现一次的字符
 *
 * 描述:
 * 请实现一个函数，用来找出字符流中第一个只出现一次的字符
 *
 * 思路:
 * 同打表
*/

class Solution
{
public:
    //Insert one char from stringstream
    Solution() : ord(0)
    {
        for (int i = 0; i < len; ++i) m[i] = -1; //not use
    }
    void Insert(char ch)
    {
        int idx = ch - ' ';
        if (m[idx] == -1) {
            m[idx] = ord++;
            //cout << char(' ' + idx) << " "<< ord  <<endl;
        }
        else if (m[idx] != -2) {
            m[idx] = -2; //重
        }
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        int Min = INT32_MAX;
        int idx = -1;
        for (int i = 0; i < len; ++i) {
            if (m[i] >= 0 && Min > m[i]) {
                Min = m[i];
                idx = i;
            }
        }
        return Min == INT32_MAX ? '#' : char(' ' + idx);
    }
private:
    static const int len = '~' - ' ' + 1;
    int m[len], ord;
};

int main() {
    Solution s;
    s.Insert('g');
    s.Insert('o');
    s.Insert('g');
    cout << s.FirstAppearingOnce() << endl;
}