#include"header.hpp"
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {

        auto partition = [&](int left, int right) {
            int pivot = nums[left];
            int l = left + 1, r = right;
            while (l <= r)
            {
                if (nums[l] < pivot and nums[r] > pivot)
                {
                    swap(nums[l++], nums[r--]);
                }
                if (nums[l] >= pivot)
                    l++;
                if (nums[r] <= pivot)
                    r--;
            }
            swap(nums[left], nums[r]);
            return r;
        };
        int left = 0;
        int right = nums.size() - 1;
        int result = 0;
        while (true)
        {
            int idx = partition(left, right);
            if (idx == k - 1)
            {
                result = nums[idx];
                break;
            }
            else if (idx > k - 1)
            {
                right = idx - 1;
            }
            else
                left = idx + 1;
        }
        return result;
    }
};