#include"header.hpp"
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        int _n = 0;
        for(int i = 0 ; i < n ; ++i)
        {
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            nums[_n] = nums[i];
            _n++;
        }
        // nums.resize(_n );
        return _n;
    }
};