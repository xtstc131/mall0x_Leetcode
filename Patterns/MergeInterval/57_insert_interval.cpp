#include "header.hpp"
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        auto comp = [](const auto &inter1, const auto &inter2) {
            return inter1[1] < inter2[0];
        };
        auto range = equal_range(intervals.begin(), intervals.end(), newInterval, comp);
        auto itr1 = range.first, itr2 = range.second;
        if (itr1 == itr2)
        {
            intervals.insert(itr1, newInterval);
        }
        else
        {
            itr2--;
            *(itr2->begin() + 0) = min(newInterval[0], *(itr1->begin() + 0));
            *(itr2->begin() + 1) = max(newInterval[1], *(itr2->begin() + 1));
            intervals.erase(itr1, itr2);
        }
        return intervals;
        // for(auto it = range.first; it < range.second; it++)
        //     cout <<"["<<  *(it->begin()) << "," <<  *(it->begin()+1)<<"]";
    }
};