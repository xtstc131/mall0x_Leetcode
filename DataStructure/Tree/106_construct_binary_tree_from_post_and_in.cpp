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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (postorder.size() == 0 || inorder.size() == 0)
            return nullptr;
        unordered_map<int, int> cache;
        int n = postorder.size();
        for (int i = 0; i < n; ++i)
            cache[inorder[i]] = i;
        return createTree(postorder, inorder, 0, n - 1, 0, n - 1, cache);
    }

    TreeNode *createTree(vector<int> &postorder, vector<int> &inorder, int post_begin, int post_end, int in_begin, int in_end, unordered_map<int, int> &cache)
    {
        if (postorder.size() <= 0 || post_begin > post_end || in_begin > in_end)
            return nullptr;
        int root_val = postorder[post_end];
        auto root = new TreeNode(root_val);
        int index = cache[root_val];
        int left_size = index - in_begin;

        root->left = createTree(postorder, inorder, post_begin, post_begin + left_size - 1, in_begin, index - 1, cache);
        root->right = createTree(postorder, inorder, post_begin + left_size, post_end - 1, index + 1, in_end, cache);

        return root;
    }
};