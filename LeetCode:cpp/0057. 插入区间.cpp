#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * 来源: LeetCode
 * 题目: 插入区间(Insert Interval)
 *
 * 描述:
 * 给出一个无重叠的 ，按照区间起始端点排序的区间列表
 * 在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）
 *
 * 示例 1:
 * 输入: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * 输出: [[1,5],[6,9]]
 *
 * 示例 2:
 * 输入: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * 输出: [[1,2],[3,10],[12,16]]
 * 解释: 这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠
 *
 * 思路:
 * 参照56.
*/


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if (intervals.empty()) return {newInterval};

        vector<Interval> rlt;
        int i = 0;
        for (; i < intervals.size() && intervals[i].end < newInterval.start; ++i)
            rlt.push_back(intervals[i]);
        if (i == intervals.size()) {
            rlt.push_back(newInterval);
            return rlt;
        } else {
            if (intervals[i].start > newInterval.end) {
                // 相离
                rlt.push_back(newInterval);
                rlt.push_back(intervals[i]);
            }
            else {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
                rlt.push_back(newInterval);
            }
            for (int j = i + 1; j < intervals.size(); ++j) {
                if (intervals[j].start <= rlt.back().end) {
                    rlt.back().end = max(rlt.back().end, intervals[j].end);
                }
                else {
                    rlt.push_back(intervals[j]);
                }
            }
            return rlt;
        }
    }
};