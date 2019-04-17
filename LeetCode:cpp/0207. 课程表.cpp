/*
 * 来源: LeetCode
 * 题目: 课程表(Course Schedule)
 *
 * 描述:
 * 现在你总共有 n 门课需要选，记为 0 到 n-1
 * 在选修某些课程之前需要一些先修课程
 * 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]
 * 给定课程总量以及它们的先决条件，判断是否可能完成所有课程的学习？
 *
 * 示例 1:
 * 输入: 2, [[1,0]]
 * 输出: true
 * 解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。
 *
 * 示例 2:
 * 输入: 2, [[1,0],[0,1]]
 * 输出: false
 * 解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。
 *
 * 思路:
 * 拓扑排序
 * 1. 找到入度为 0 的结点
 * 2. 打印1.中的结点，并去掉所有以1. 中结点为出发的边
 * 3. 重复1，2直到没有入度为0的点
 * 4. 如果最后打印结点数小于总结点数，说明图中有环
 *
 * 可以利用bfs实现，即queue
 */
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int cnt = 0;
        queue<int> Q;
        vector<int> in(numCourses); //记录每个结点的入度
        for (auto p : prerequisites) ++in[p.first];
        for (int i = 0; i < numCourses; ++i)
            if (0 == in[i]) Q.push(i);

        while(!Q.empty()) {
            int cur = Q.front();
            Q.pop();
            ++cnt;
            for (auto p : prerequisites) {
                if (cur == p.second && 0 == --in[p.first])
                    Q.push(p.first);
            }
        }
        return cnt == numCourses;
    }
};
