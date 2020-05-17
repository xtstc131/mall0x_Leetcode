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
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        queue<TreeNode *> _queue;
        _queue.push(root);
        int res = 0;
        while (!_queue.empty())
        {
            int size = _queue.size();
            ++res;
            for (int i = 0; i < size; ++i)
            {
                auto cur = _queue.front();
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