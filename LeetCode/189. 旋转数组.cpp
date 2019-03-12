#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 旋转数组(Rotate Array)
 *
 * 描述:
 * 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数
 *
 * 示例 1:
 * 输入: [1,2,3,4,5,6,7] 和 k = 3
 * 输出: [5,6,7,1,2,3,4]
 *
 * 解释:
 * 向右旋转 1 步: [7,1,2,3,4,5,6]
 * 向右旋转 2 步: [6,7,1,2,3,4,5]
 * 向右旋转 3 步: [5,6,7,1,2,3,4]
 *
 * 示例 2:
 * 输入: [-1,-100,3,99] 和 k = 2
 * 输出: [3,99,-1,-100]
 *
 * 解释:
 * 向右旋转 1 步: [99,-1,-100,3]
 * 向右旋转 2 步: [3,99,-1,-100]
 *
 * 思路:
 * 1. 逐位替换, i -> (i + k) % len
 * 2. 但是，如果 k 和 len 不互质时会出现多条环路，因此要计算出
 * 环路数 = gcd(k, len)， 每条环路的结点数 n = len / gcd(k, len)
 * 一开始从下标 0 出发开始替换，当步长为 n 时，从 1 重新出发以避免陷入死环
*/

class Solution {
public:
    inline int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;
        if (len <= 1 || k == 0) return;
        int cnt = 0, i = 0, j = 0, prev = nums[0], tmp = nums[0];

        int t = len / gcd(len, k);

        int cnt2 = 0;
        while(cnt < len) {
            j = (i + k) % len;
            prev = nums[j];
            nums[j] = tmp;
            tmp = prev;
            i = j;

            ++cnt2;
            ++cnt;
            if (cnt2 == t) {
                cnt2 = 0;
                i++;
                tmp = nums[i];
            }
        }
    }
};
