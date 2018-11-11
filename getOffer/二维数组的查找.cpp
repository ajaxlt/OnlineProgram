#include <vector>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 二维数组的查找
 *
 * 描述: 在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
 * 每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数
 *
 * 思路: 从左下角或者右上角找起, 若大了，向上; 若小了，向右
 */
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if (array.empty()) return -1;
        int x = array.size() - 1, y = 0;
        while (x >= 0 && y < array[0].size()) {
            if (target == array[x][y]) return true;
            else if (target < array[x][y]) --x;
            else ++y;
        }
        return false;
    }
};
