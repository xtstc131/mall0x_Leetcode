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
    int diameterOfBinaryTree(TreeNode *root)
    {
        helper(root);
        return ans;
    }

private:
    int ans;
    int helper(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int _left = helper(root->left);
        int _right = helper(root->right);
        ans = max(ans, _left + _right);
        return max(_left, _right) + 1;
    }
};