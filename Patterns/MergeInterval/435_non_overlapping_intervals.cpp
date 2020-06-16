#include "header.hpp"
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        auto comp = [](const auto &inter1, const auto &inter2) {
            return inter1[1] < inter2[1];
        };
        sort(intervals.begin(), intervals.end(), comp);
        int pre = 0;
        int res = 0;
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals[pre][1] > intervals[i][0])
            {
                res++;
            }
            else
                pre = i;
        }
        return res;
    }
};