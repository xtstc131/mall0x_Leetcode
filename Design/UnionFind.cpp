#include "../header.hpp"
class UnionFind
{
private:
    /* data */
    int _size;
    vector<int> tree;
    vector<int> rank;

public:
    UnionFind(int n)
    {
        _size = n;
        tree.resize(_size, 0);
        rank.resize(_size, 0);
        for(int i = 0; i < n; ++i)
        {
            tree[i] = i;
        }
    }
    // Recursion Ver.
    int find(int x)
    {
        if(x != tree[x])
            tree[x] = find(tree[x]);
        return tree[x];
    }

    // While Loop Ver.
    int _find(int x)
    {
        while(x != tree[x])
        {
            // x.parent = x.parent.parent
            // Set grandparent as parent to decrease (half) path distance
            tree[x] = tree[tree[x]];
            // x = x.parent
            x = tree[x];
        }
        return x;
    }
    bool merge(int x, int y)
    {
        int p = find(x);
        int q = find(y);
        if(p == q)
            return false;
        if(rank[p] > rank[q])
        {
            tree[q] = p;
        }
        else 
        {
            tree[p] = q;
            if(rank[q] == rank[p])
                rank[q] ++;
        }
        return true;
    }
    void print()
    {
        cout << "ID Array:\n";
        for(auto p : tree)
            cout << p <<" ";
        cout << endl;
    }
    ~UnionFind()
    {

    }
};

int main()
{

    UnionFind uf = UnionFind(10);
    uf.merge(1,0);
    uf.merge(2,0);
    uf.merge(9,0);
    uf.merge(3,4);
    uf.merge(3,9);
    cout << uf.find(3);
    uf.print();
    return 0;
}