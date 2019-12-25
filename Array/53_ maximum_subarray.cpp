#include "header.hpp"
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = -numeric_limits<int>::max();
        int cur = nums[0];
        for(int i = 0 ; i< nums.size(); ++i)
        {
            cur = max(cur + nums[i],nums[i]);
            res = max(cur, res);
        }
        return res;
    }
};