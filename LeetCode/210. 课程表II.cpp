/*
 * 来源: LeetCode
 * 题目: 课程表II(Course Schedule II)
 *
 * 描述:
 * 现在你总共有 n 门课需要选，记为 0 到 n-1
 * 在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]
 * 给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序
 * 可能会有多个正确的顺序，你只要返回一种就可以了。如果不可能完成所有课程，返回一个空数组
 *
 * 思路:
 * 拓扑排序
 * 与 210. 相同
 *
 */
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        int cnt = 0;
        queue<int> Q;
        vector<int> in(numCourses); //记录每个结点的入度
        for (auto p : prerequisites) ++in[p.first];
        for (int i = 0; i < numCourses; ++i)
            if (0 == in[i]) Q.push(i);

        while(!Q.empty()) {
            int cur = Q.front();
            Q.pop();
            tmp.push_back(cur);
            ++cnt;
            for (auto p : prerequisites) {
                if (cur == p.second && 0 == --in[p.first])
                    Q.push(p.first);
            }
        }
        return cnt == numCourses ? tmp : vector<int>();
    }
private:
    vector<int> tmp;
};