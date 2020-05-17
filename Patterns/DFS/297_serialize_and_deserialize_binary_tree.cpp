/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "header.hpp"
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        std::string result = "";
        std::queue<TreeNode *> _bfs;
        if (!root)
            return result;
        else
        {
            _bfs.push(root);
            while (!_bfs.empty())
            {
                TreeNode *current = _bfs.front();
                _bfs.pop();
                if (current)
                {
                    result += std::to_string(current->val);
                    _bfs.push(current->left);
                    _bfs.push(current->right);
                }
                else
                    result += '!';
                result += ',';
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        int index = 0;
        TreeNode *root = nullptr;
        if (data.empty())
            return root;
        else
        {
            std::queue<TreeNode *> _bfs;
            (data, index, _bfs, root);
            while (!_bfs.empty())
            {
                TreeNode *current = _bfs.front();
                _bfs.pop();
                processNext(data, index, _bfs, current->left);
                processNext(data, index, _bfs, current->right);
            }
            return root;
        }
    }

private:
    void processNext(const std::string &data, int &i, queue<TreeNode *> &_bfs, TreeNode *&p)
    {
        int initial = i;
        i = data.find(",", i);
        ++i;

        string temp = data.substr(initial, i - initial - 1);
        if (temp[0] != '!')
        {
            p = new TreeNode(stoi(temp));
            _bfs.push(p);
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));