
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
private:
    vector<int> res;

public:
    void helper(TreeNode *root)
    {
        if (!root)
            return;
        else
        {
            res.push_back(root->val);
            helper(root->left);
            helper(root->right);
        }
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        helper(root);
        return res;
    }
};