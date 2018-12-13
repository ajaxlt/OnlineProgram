#include <iostream>
#include <vector>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 数组中只出现一次的数字
 *
 * 描述:
 * 一个整型数组里除了两个数字之外，其他的数字都出现了偶数次
 * 请写程序找出这两个只出现一次的数字
 *
 * 思路:
 * xor，两个相同的数字xor结果为0
 * 对于本题，将所有数字xor后，结果一定是两个目标数的xor，因为其余会自我抵消
 *
 *
 * 但是，我们需要将两个目标数分开，分别处理，即用一个标志去区别两者，我们先记先前的结果为rlt
 * 可以针对最后这两个数的xor作为突破，根据xor的性质，rlt每位上的1即标记着两个目标数的不同
 *
 * 方便起见，我们从低位开始取第一个1作为判断标志即可，假设该位是i
 * 那么对于原来的所有数字，我们可以根据第i位是不是1而分成两组，分别进行异或
 * 两组最后的结果便是两个目标数
*/

class Solution {
public:
    /* 异或 大法 */
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if (data.size() < 2) return;
        int tmp = 0, bit = 1;
        for (int i : data) tmp ^= i;
        while(!(tmp & 1)) {
            tmp >>= 1;
            bit <<= 1;
        }
        *num1 = *num2 = 0;
        for (int i : data) {
            if (i & bit) *num1 ^= i;
            else *num2 ^= i;
        }
    }
};
int main() {
    vector<int> a = {4,4,1,2};
    int n1, n2;
    Solution s;
    s.FindNumsAppearOnce(a, &n1, &n2);
    cout << n1 << " " << n2 << endl;
}