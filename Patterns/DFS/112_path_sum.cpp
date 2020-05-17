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
    bool hasPathSum(TreeNode *root, int sum)
    {
        return helper(root, sum);
    }

    bool helper(TreeNode *root, int sum)
    {
        if (root == nullptr)
            return false;
        if (root->left == nullptr && root->right == nullptr && root->val == sum)
            return true;
        return helper(root->left, sum - root->val) || helper(root->right, sum - root->val);
    }
};