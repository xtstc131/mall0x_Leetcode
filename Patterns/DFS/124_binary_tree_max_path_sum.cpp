#include "header.hpp"
//  Definition for a binary tree node.
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
    int maxPathSum(TreeNode *root)
    {
        max_value = INT_MIN;
        helper(root);
        return max_value;
    }

    int helper(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int lvalue = helper(root->left);
        int rvalue = helper(root->right);
        lvalue = max(0, lvalue);
        rvalue = max(0, rvalue);
        max_value = max(max_value, lvalue + rvalue + root->val);
        return max(lvalue, rvalue) + root->val;
    }

private:
    int max_value;
};