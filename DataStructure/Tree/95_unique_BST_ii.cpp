#include "header.hpp"
class Solution
{
public:
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return {};
        return helper(1, n);
    }
    vector<TreeNode *> helper(int begin, int end)
    {
        if (begin > end)
            return {nullptr};
        if (begin == end)
            return {new TreeNode(begin)};
        vector<TreeNode *> result;
        for (int i = begin; i <= end; ++i)
        {
            auto ltree = helper(begin, i - 1);
            auto rtree = helper(i + 1, end);

            for (auto &l : ltree)
                for (auto &r : rtree)
                {
                    auto root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    result.push_back(root);
                }
        }
        return result;
    }
};