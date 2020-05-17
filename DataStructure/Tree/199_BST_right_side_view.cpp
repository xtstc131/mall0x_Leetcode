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
    vector<int> rightSideView(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        vector<int> res;
        queue<TreeNode *> _queue;
        _queue.push(root);

        while (!_queue.empty())
        {
            int size = _queue.size();
            for (int i = 0; i < size; ++i)
            {
                auto cur = _queue.front();
                if (i == size - 1)
                    res.push_back(cur->val);
                _queue.pop();
                if (cur->left)
                    _queue.push(cur->left);
                if (cur->right)
                    _queue.push(cur->right);
            }
        }
        return res;
    }
};