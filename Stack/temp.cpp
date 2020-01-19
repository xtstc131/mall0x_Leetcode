/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<TreeNode *> generateTrees(int n)
    {
        return helper(1, n);
    }
    vector<TreeNode *> helper(int left, int right)
    {
        if (left > right)
            return {nullptr};
        if (left == right)
            return {new TreeNode(left)};
        vector<TreeNode*> result;
        for (int i = left; i <= right; ++i)
        {
            auto ltree = helper(left, i - 1);
            auto rtree = helper(i + i, right);

            for (auto &l : ltree)
                for (auto & r : rtree)
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