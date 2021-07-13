#include "header.hpp"
class SegmentTree {
public:
    SegmentTree(vector<int>& nums) {
        n = nums.size();
        tree.resize(n * 2);
        buildTree(nums);
    }
    
    void update(int index, int val) {
        index += n;
        tree[index] = val;
        while(index)
        {
            int left = index;
            int right = index;
            if(index % 2 == 0)
                right = index + 1;
            else
                left = index - 1;
            tree[index/2] = tree[left] + tree[right];
            index/=2;
        }
    }
    
    int sumRange(int left, int right) {
        left += n;
        right += n;
        int sum = 0;
        while(left <= right)
        {
            if(left % 2 == 1)
            {
                sum += tree[left];
                left++;
            }
            if(right % 2 == 0)
            {
                sum += tree[right];
                right--;
            }
            right /= 2;
            left /=2;
        }
        return sum;
    }
private:
    vector<int> tree;
    int n;
    void buildTree(vector<int>& nums)
    {
        for(int i = n, j = 0; i < n*2; ++i, ++j)
        {
            tree[i] = nums[j];
        }
        for(int i = n-1 ; i > 0; --i)
        {
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }
};