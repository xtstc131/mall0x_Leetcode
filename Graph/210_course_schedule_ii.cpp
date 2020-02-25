#include "header.hpp"
class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto _pair : prerequisites)
        {
            graph[_pair[1]].push_back(_pair[0]);
            ++indegree[_pair[0]];
        }

        queue<int> _queue;
        vector<int> result;
        int count = 0;
        for (int i = 0; i < numCourses; ++i)
        {
            if (indegree[i] == 0)
                _queue.push(i);
        }

        while (!_queue.empty())
        {
            int cur = _queue.front();
            _queue.pop();
            ++count;
            result.push_back(cur);
            for (auto v : graph[cur])
            {
                if (--indegree[v] == 0)
                    _queue.push(v);
            }
        }
        vector<int> wrongOrder;
        return count == numCourses ? result : wrongOrder;
    }
};