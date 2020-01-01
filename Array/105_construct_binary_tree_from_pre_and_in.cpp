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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() == 0 || inorder.size() == 0)
            return nullptr;
        unordered_map<int, int> cache;
        int n = preorder.size();
        for (int i = 0; i < n; ++i)
            cache[inorder[i]] = i;
        return createTree(preorder, inorder, 0, n - 1, 0, n - 1, cache);
    }

    TreeNode *createTree(vector<int> &preorder, vector<int> &inorder, int pre_begin, int pre_end, int in_begin, int in_end, unordered_map<int, int> &cache)
    {
        if (preorder.size() <= 0 || pre_begin > pre_end || in_begin > in_end)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[pre_begin]);
        int index = cache[preorder[pre_begin]];
        root->left = createTree(preorder, inorder, pre_begin + 1, pre_begin + index - in_begin, in_begin, index - 1, cache);
        root->right = createTree(preorder, inorder, pre_begin + index - in_begin + 1, pre_end, index + 1, in_end, cache);

        return root;
    }
};