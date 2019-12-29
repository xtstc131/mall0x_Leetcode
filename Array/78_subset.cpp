#include "header.hpp"
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int shift = 1 << n;
        vector<vector<int>> res(shift);
        for(int i = 0 ; i < shift ; ++i)
        {
            for(int j = 0 ; j < n ; ++j)
            {
                if((i >> j) & 1)
                {
                    res[i].push_back(nums[j]);
                }
            }
        }
        return res;
    }
};