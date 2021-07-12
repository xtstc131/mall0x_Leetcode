#include "header.hpp"
class TrieNode
{
public:
    bool wordend;
    vector<TrieNode*> children;
    char content;

    TrieNode() : content(' '), wordend(false){};
    TrieNode(char ch) : content(ch), wordend(false){}
    ~TrieNode()
    {
        for (auto child : children)
        {
            delete child;
        }
    }

    TrieNode* subNode(char ch)
    {
        if (children.empty())
            return nullptr;
        for(auto child : children)
            if( ch == child->content)
                return child;
        return nullptr;
    }
    
private:

};


class Trie
{
public:
    Trie()
    {
        root = new TrieNode();
    }
    
void insert(string word)
{
    if (search(word))
        return;
    auto cur = root;
    for(auto & ch: word)
    {
        auto parent = cur;
        cur = cur->subNode(ch);
        if(cur == nullptr)
        {
            auto newNode = new TrieNode(ch);
            parent->children.push_back(newNode);
            cur = newNode;
        }
    }
    cur->wordend = true;
}

bool beginWith(string prefix)
{
    auto cur = root;
    for(auto &ch : prefix)
    {
        cur = cur->subNode(ch);
        if(cur == nullptr)
            return false;
    }
    return true;
}

bool search(string word)
{
    auto cur = root;
    for(auto &ch : word)
    {
        cur = cur->subNode(ch);
        if(cur == nullptr)
            return false;
    }
    return cur->wordend;
} 
private:
    TrieNode * root;


};