#include"header.hpp"
class Keepvalue
{
    int &myref;
    const int remember;

public:
    Keepvalue(int &ref) : myref(ref), remember(myref){};
    ~Keepvalue()
    {
        myref = remember;
    }
};


int main()
{
    int i = 7;
    cout << i << endl;
    cout << & i << endl;
    {   
        Keepvalue k(i);
        i = 5;
        cout << i << endl;
        cout << & i <<endl;
        i = 3;
    }
    cout << i;

}