#include <iostream>
#include <vector>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 调整数组顺序使奇数位于偶数前面
 *
 * 描述: 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分
 * 所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变
 *
 * 思路:
 * 主要是参考快排的思路。
 * 因为限定了相对位置不变，因此需要多一个for循环进行挪位
 *
*/
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if (array.size() == 0 ||  array.size() == 1) return;
        int i = 0; // i + 1表示奇数个数
        for (int j = 0; j < array.size(); ++j) {
            if (array[j] % 2 != 0) {
                int x = array[j];
                for (int k = j; k > i; --k) array[k] = array[k - 1];
                array[i++] = x;
            }
        }
    }
};