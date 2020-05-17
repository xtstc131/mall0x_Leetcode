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
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        helper(root, sum);
        return res;
    }

    void helper(TreeNode *root, int &sum)
    {
        if (root == nullptr)
            return;
        int v = root->val;
        sum -= v;
        path.push_back(v);
        if (sum == 0 && !root->left && !root->right)
        {
            res.push_back(path);
        }
        if (root->left)
            helper(root->left, sum);
        if (root->right)
            helper(root->right, sum);
        sum += v;
        path.pop_back();
    }

private:
    vector<vector<int>> res;
    vector<int> path;
};