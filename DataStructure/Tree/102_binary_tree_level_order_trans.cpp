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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        queue<TreeNode *> _queue;
        _queue.push(root);
        vector<vector<int>> res;
        while (!_queue.empty())
        {
            int size = _queue.size();
            vector<int> level;
            for (int i = 0; i < size; ++i)
            {
                auto cur = _queue.front();
                level.push_back(cur->val);
                _queue.pop();
                if (cur->left)
                    _queue.push(cur->left);
                if (cur->right)
                    _queue.push(cur->right);
            }
            res.push_back(level);
        }
        return res;
    }
};