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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        if (!root)
            return vector<vector<int>>();
        deque<vector<int>> vdeque;
        queue<TreeNode *> BFQ;
        BFQ.push(root);
        while (!BFQ.empty())
        {
            auto n = BFQ.size();
            vector<int> v;
            for (int i = 0; i < n; ++i)
            {
                auto node = BFQ.front();
                v.push_back(node->val);
                BFQ.pop();
                if (node->left)
                    BFQ.push(node->left);
                if (node->right)
                    BFQ.push(node->right);
            }
            vdeque.push_front(v);
        }
        return vector<vector<int>>(vdeque.begin(), vdeque.end());
    }
};