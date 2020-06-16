#include "header.hpp"
class Solution
{
public:
    int findMaximizedCapital(int k, int W, vector<int> &Profits, vector<int> &Capital)
    {
        //max heap
        priority_queue<int> pq;

        int n = Profits.size();
        vector<pair<int, int>> products(n);
        for (int i = 0; i < n; ++i)
        {

            products[i] = {Profits[i], Capital[i]};
        }

        sort(products.begin(), products.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return a.second < b.second;
        });
        int size = 0;
        while (k--)
        {
            while (size < n && products[size].second <= W)
            {
                pq.push(products[size].first);
                size++;
            }
            if (!pq.empty())
            {
                W += pq.top();
                pq.pop();
            }
        }
        return W;
    }
};