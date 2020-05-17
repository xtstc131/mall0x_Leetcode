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
    vector<int> distanceK(TreeNode *root, TreeNode *target, int K)
    {
        vector<int> res;
        unordered_set<TreeNode *> visited;
        queue<TreeNode *> bfs;
        buildGraph(nullptr, root);
        visited.insert(target);
        bfs.push(target);
        int k = 0;
        while (!bfs.empty() && k <= K)
        {
            int size = bfs.size();
            for (int i = 0; i < size; ++i)
            {
                auto node = bfs.front();
                bfs.pop();
                if (k == K)
                    res.push_back(node->val);
                for (auto neighbour : g[node])
                {
                    if (visited.count(neighbour))
                        continue;
                    bfs.push(neighbour);
                    visited.insert(neighbour);
                }
            }
            k++;
        }
        return res;
    }

private:
    unordered_map<TreeNode *, vector<TreeNode *>> g;
    void buildGraph(TreeNode *parent, TreeNode *child)
    {
        if (parent)
        {
            g[child].push_back(parent);
            g[parent].push_back(child);
        }
        if (child->left)
            buildGraph(child, child->left);
        if (child->right)
            buildGraph(child, child->right);
    }
};