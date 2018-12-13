#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
 * 来源: 剑指Offer
 * 题目: 数据流中的中位数
 *
 * 描述:
 * 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值
 * 如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数
 *
 * 思路：
 * 把数据流分两块，左和右，左右的元素个数差不大于1
 * 我们能够在O(1)的时间取得左的最大，和右的最大
 * 最大堆和最小堆是不错的选择，当然也可以用优先队列
 *
 * 1. 插入:
 *    1.1 判断元素总数的奇偶性: 如果是偶数，则放到右边(最小堆);反之，则放到左边(最大堆)
 *    1.2 不过，我们应该总是保证左边的元素不大于右边的元素
 *    对于偶数情况，我们应该判断新元素是否比左边最大的还要大，如果是，则可以直接放到右边;
 *    否则，我们应该先放到左边，然后把左边最大的拿出来，再放到右边
 *    对于奇数情况也是同理
 *
 * 2. 取中位数:
 *    2.1 如果元素的总数是偶数，则一定返回(left_max + right_min) / 2.0
 *    2.2 如果元素的总数是奇数，因为右边的元素总是大于等于左边的，故此时左边为偶数个，右边为奇数个
 *    因此一定时返回right_min
 *
*/
class Solution {
public:
    void Insert(int num)
    {
        const size_t size = left.size() + right.size();
        if(!(size & 1)) { // 偶数时，是要放入最小堆(右边)
            // 先检查，我们要保证左边最大的放到右边来，因此看一下num是不是比左边最大的大
            if (!left.empty() && num < left.top()) {
                left.push(num);
                num = left.top(); // 最大堆的最大
                left.pop();
            }
            right.push(num);
        }
        else { // 奇数时, 是要放到最大堆(左边)
            //先检查，我们要保证右边最小的放到左边来，因此要看一下num是不是比右边最小的小
            if (num > right.top()) {
                right.push(num);
                num = right.top();
                right.pop();
            }
            left.push(num);
        }
    }
    double GetMedian()
    {
        const size_t size = left.size() + right.size();
        if (!size) throw("No");
        else if (!(size & 1)) return (left.top() + right.top()) / 2.0;
        else return double(right.top());
    }
private:
    priority_queue<int> left; // 左边 最大堆
    priority_queue<int, vector<int>, greater<int>> right; // 右边 最小堆
};
