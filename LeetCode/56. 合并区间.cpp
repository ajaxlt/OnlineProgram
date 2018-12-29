#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 合并区间(Merge Intervals)
 *
 * 描述:
 * 给出一个区间的集合，请合并所有重叠的区间。
 *
 * 示例 1:
 * 输入: [[1,3],[2,6],[8,10],[15,18]]
 * 输出: [[1,6],[8,10],[15,18]]
 * 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 *
 * 示例 2:
 * 输入: [[1,4],[4,5]]
 * 输出: [[1,5]]
 * 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
 *
 * 思路:
 * 自定义排序
*/


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
bool cmp(const Interval& a, const Interval& b) {
    return a.start == b.start ? a.end < b.end : a.start < b.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> rlt;
        if (intervals.size() == 0) return rlt;
        if (intervals.size() == 1) return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        rlt.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start <= rlt[rlt.size() - 1].end) {
                rlt[rlt.size() - 1].end = max(rlt[rlt.size() - 1].end, intervals[i].end);
            } else {
                rlt.push_back(intervals[i]);
            }
        }
        return rlt;
    }
};