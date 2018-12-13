#include <iostream>
#include <vector>
#include <string.h>
#include <map>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 数组中出现次数超过一半的数字
 *
 * 描述:
 * 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字
 * 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}
 * 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2，如果不存在则输出0
 *
 * 思路：
 * 1. 基于map的计数, O(n)
 * 2. 基于快速排序, O(n)
 * 3. 计数法, O(n)
 *
*/
/**
 * Solution1. 基于map
 */
class Solution1 {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty()) return 0;
        map<int, int> cnt;
        int th = numbers.size() / 2;
        for (int i = 0; i < numbers.size(); ++i) {
            if (!cnt.count(numbers[i])) cnt[numbers[i]] = 1;
            else ++cnt[numbers[i]];
        }
        map<int, int>::iterator it;
        for (it = cnt.begin(); it != cnt.end(); ++it) {
            if (it -> second > th) return it -> first;
        }
        return 0;
    }
};
/**
 * Solution2. 基于Partition
 * 出现次数超过一半的，一定是中位数，反之则不然
 */
class Solution2 {
public:
    /**
     * @brief 检查是否过半
     * @param numbers
     * @param i 判断元素
     * @return i or 0
     */
    int CheckMoreThanHalf(vector<int> numbers, int i) {
        int half = numbers.size() / 2, cnt = 0;
        for (auto k : numbers)
            if (k == i) ++cnt;
        if (cnt > half) return i;
        else return 0;
    }
    /**
     * @brief 快排核心思维
     */
    int Partition(vector<int>& numbers, int p, int r) {
        int x = numbers[r]; //主元
        int i = p;
        for (int j = p; j < r; ++j) {
            if (numbers[j] <= x)
                swap(numbers[i++], numbers[j]);
        }
        swap(numbers[i], numbers[r]);
        return i;
    }
    /**
     * @brief 二分法查找
     */
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty()) return 0;
        if (numbers.size() == 1) return numbers[0];
        int p = 0, r = numbers.size() - 1;
        while(p < r) {
            int q = Partition(numbers, p, r);
            int half = (p + r) / 2;
            if (q == half) return CheckMoreThanHalf(numbers, numbers[q]);
            else if (q < half) p = q + 1;
            else r = q - 1;
        }
        return 0;
    }
};
/**
 * Solution2. 计数法
 * 假若 x 出现的次数超过一半，则不为 x 的数一定是少于一半的
 */
class Solution3 {
public:
    int CheckMoreThanHalf(vector<int> numbers, int i) {
        int half = numbers.size() / 2, cnt = 0;
        for (auto k : numbers)
            if (k == i) ++cnt;
        if (cnt > half) return i;
        else return 0;
    }
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty()) return 0;
        if (numbers.size() == 1) return numbers[0];
        int crt = numbers[0], cnt = 1;
        for (int i = 1; i < numbers.size(); ++i) {
            if (numbers[i] == crt) ++cnt;
            else {
                --cnt;
                if (cnt == 0) {
                    crt = numbers[i];
                    cnt = 1;
                }
            }
            cout << cnt << endl;
        }
        return CheckMoreThanHalf(numbers, crt);
    }
};
int main() {
    Solution3 s;
    vector<int> num = {2,2,2,2,2,1,3,4,5};
    cout << s.MoreThanHalfNum_Solution(num) << endl;
    return 0;
}