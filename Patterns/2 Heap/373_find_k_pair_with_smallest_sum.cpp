#include"header.hpp"    
class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {

        auto comp = [](vector<int> &a, vector<int> &b) {
            return a[0] + a[1] < b[0] + b[1];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);

        vector<vector<int>> res;
        for (int i = 0; i < min((int)nums1.size(), k); i++)
        {
            for (int j = 0; j < min((int)nums2.size(), k); j++)
            {
                if (pq.size() < k)
                    pq.push({nums1[i], nums2[j]});
                else if (nums1[i] + nums2[j] < pq.top()[0] + pq.top()[1])
                {
                    pq.push({nums1[i], nums2[j]});
                    pq.pop();
                }
            }
        }
        while (!pq.empty())
        {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};