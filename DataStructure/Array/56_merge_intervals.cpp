#include "header.hpp"
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
            return intervals;
        // sort in ascending order based on lowest digit
        // make sure you're using const ref, otherwise sort will be slow
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) {
            return b[0] > a[0];
        });

        vector<vector<int>> res;
        int i = 0;

        while (i < intervals.size() - 1)
        {
            // if the highest digit of intervals[i] is bigger or equal
            // to the lowest digit of intervals[i + 1], there's an overlap
            if (intervals[i][1] >= intervals[i + 1][0])
            {
                // copy the merged range over to intervals[i + 1]
                // intervals[i][0] is always smaller or equal becaue of the sort
                // but it's not necessarily the case for intervals[i][1] so we're using max
                intervals[i + 1][0] = intervals[i][0];
                intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);
            }
            else
            {
                res.push_back(intervals[i]);
            }
            i++;
        }
        // the loop ends one element before the end so we will
        // always have a single left-over
        res.push_back(intervals[i]);

        return res;
    }
};