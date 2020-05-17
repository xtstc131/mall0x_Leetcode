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
    bool isBalanced(TreeNode *root)
    {
        height(root);
        return res;
    }

    int height(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left = height(root->left);
        int right = height(root->right);
        if (abs(left - right) > 1)
            res = false;
        return max(left, right) + 1;
    }

private:
    bool res = true;
};