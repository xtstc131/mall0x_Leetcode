#include "header.hpp"
class TrieNode
{
public:
    char content;
    bool isEnd;
    int shared;
    vector<TrieNode *> children;

    TrieNode() : content(' '), isEnd(false), shared(0){};
    TrieNode(char ch) : content(ch), isEnd(false), shared(0) {}
    ~TrieNode()
    {
        for (auto child : children)
        {
            delete child;
        }
    }

    TrieNode *subNode(char ch)
    {
        if (children.empty())
            return nullptr;
        for (auto child : children)
        {
            if (child->content == ch)
                return child;
        }
        return nullptr;
    }
};
class Trie
{
public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode();
    }
    // ~Trie()
    // {
    //     delete root;
    // }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        if (search(word))
            return;
        auto cur = root;
        for (auto ch : word)
        {
            auto child = cur->subNode(ch);
            if (child != nullptr)
                cur = child;
            else
            {
                auto newNode = new TrieNode(ch);
                cur->children.push_back(newNode);
                cur = newNode;
            }
            ++cur->shared;
        }
        cur->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        auto cur = root;
        for (auto ch : word)
        {
            cur = cur->subNode(ch);
            if (cur == nullptr)
                return false;
        }
        return cur->isEnd == true;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        auto cur = root;
        for (auto ch : prefix)
        {
            cur = cur->subNode(ch);
            if (cur == nullptr)
                return false;
        }
        return true;
    }

private:
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */