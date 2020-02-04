#include "header.hpp"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        stack<TreeNode *> _stack;
        vector<int> res;
        _stack.push(root);
        while (!_stack.empty())
        {
            auto cur = _stack.top();
            res.push_back(cur->val);
            _stack.pop();
            if (cur->right)
            {
                _stack.push(cur->right);
            }
            if (cur->left)
            {
                _stack.push(cur->left);
            }
        }
        return res;
    }
};