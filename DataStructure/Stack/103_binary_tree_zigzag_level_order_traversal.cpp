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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        queue<TreeNode *> _queue;
        _queue.push(root);
        bool reverse = false;
        vector<vector<int>> res;
        while (!_queue.empty())
        {
            int size = _queue.size();
            vector<int> cur_level(size);
            for (int i = 0; i < size; ++i)
            {
                auto cur = _queue.front();
                _queue.pop();
                if (reverse)
                {
                    cur_level[size - i - 1] = cur->val;
                }
                else
                {
                    cur_level[i] = cur->val;
                }
                if (cur->left)
                    _queue.push(cur->left);
                if (cur->right)
                    _queue.push(cur->right);
            }
            res.push_back(cur_level);
            reverse = !reverse;
        }
        return res;
    }
};