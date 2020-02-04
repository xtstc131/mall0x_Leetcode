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
    void helper(TreeNode *root, int sum)
    {
        if (root == nullptr)
            return;

        sum = sum * 10 + root->val;

        if (root->left == nullptr && root->right == nullptr)
        {
            total += sum;
            return;
        }

        helper(root->left, sum);
        helper(root->right, sum);
    }

    int sumNumbers(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        helper(root, 0);
        return total;
    }

private:
    int total = 0;
};