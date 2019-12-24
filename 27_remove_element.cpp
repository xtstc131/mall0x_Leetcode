class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int _n = 0;
        for(int i = 0 ; i < n ; ++i)
        {
            if(nums[i] == val) continue;
            nums[_n++] = nums[i];
        }
        return _n;
    }
};