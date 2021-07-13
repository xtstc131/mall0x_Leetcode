#include "header.hpp"

class BIT
{
private:
    vector<int> tree;
    int _size;

public:
    BIT(int n)
    {
        _size = n;
        tree.resize(n+1);
        for(int i = 0 ;i <= n ; ++i)
            tree[i] = 0;
    }
    int lowbit(int x)
    {
        return x & (-x);
    }
    void update(int index, int delta)
    {
        while(index <= _size)
        {
            tree[index] += delta;
            index += lowbit(index);
        }
    }

    int query(int index)
    {
        int res = 0;
        while(index > 0)
        {
            res += tree[index];
            index -= lowbit(index);
        }
        return res;
    }

};