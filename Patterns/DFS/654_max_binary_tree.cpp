#include "header.hpp"
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return nullptr;
        return helper(0, n - 1, nums);
    }

    TreeNode *helper(int l, int r, vector<int> &nums)
    {
        if (l > r)
            return nullptr;
        int idxMax = l;
        // i <= r
        for (int i = l; i <= r; ++i)
        {
            if (nums[i] > nums[idxMax])
                idxMax = i;
        }
        auto node = new TreeNode(nums[idxMax]);
        node->left = helper(l, idxMax - 1, nums);
        node->right = helper(idxMax + 1, r, nums);
        return node;
    }
};