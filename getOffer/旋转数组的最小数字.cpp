#include <iostream>
#include <vector>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 旋转数组中最小的数字
 *
 * 描述: 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转
 * 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。
 * 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1
 * 注意：给出的所有元素都大于0，若数组大小为0，请返回0。
 *
 * 思路:
 * 考虑左单调还是右单调
*/
class Solution {
public:
    int findMin(vector<int> a, int head, int tail) {
        if (head == tail) return a[head];

        int mid = (head + tail) / 2;
        if (a[mid] >= a[head]) {
            //左单调
            return min(a[head], findMin(a, mid + 1, tail));
        } else {
            //右单调
            if (mid == head)
                return a[mid];
            else
                return min(a[mid], findMin(a, head, mid - 1));
        }
    }
    int minNumberInRotateArray(vector<int> rotateArray) {
        return findMin(rotateArray, 0, rotateArray.size() - 1);
    }
};
