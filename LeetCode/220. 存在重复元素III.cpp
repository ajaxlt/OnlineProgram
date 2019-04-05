/*
 * 来源: LeetCode
 * 题目: 存在重复元素 III(Contains Duplicate III)
 *
 * 描述:
 * 给定一个整数数组，判断数组中是否有两个不同的索引 i 和 j
 * 使得 nums [i] 和 nums [j] 的差的绝对值最大为 t，并且 i 和 j 之间的差的绝对值最大为 ķ
 *
 * 思路:
 * 利用 set(红黑树) 实现滑动窗口
 * lower_bound(x) -> 返回集合中第一个大于等于 x 的值
 *
 * 一个问题: set 里的元素是唯一的, 如果数组存在相同元素的话，是否会丢失信息？
 * 不会。
 * 假定 a[i] = a[j], j > i
 * 1. 如果相同元素在同一个窗口里(j - i <= t)，则遍历到 a[j] 时, a[i] 仍在set中
 * 2. 如果相同元素不在同一个窗口里(j - i > t)，则遍历到 a[j] 时, a[i] 已经不在
 * 因此 a[j] 可以成功地加入到 set 中，不会丢失信息
 */
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> book; //防溢出, 以下减法运算均化long long

        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) book.erase(nums[i - k - 1]); // 删除窗口头

            // 找到第一个大于等于 nums[i] - t 的数
            set<long long>::iterator it = book.lower_bound((long long) nums[i] - (long long) t);
            // tar >= nums[i] - t  -> t >= nums[i] - tar
            // t >= tar - nums[i]
            if (it != book.end() && (long long) t >= (*it) - (long long) nums[i]) return true;
            book.insert(nums[i]);
        }
        return false;
    }
};