#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
class show
{

public:
    void abc()
    {
        cout << "Hii" << endl;
    }
    void abc(string name)
    {
        cout << "Hello boy" << endl;
    }

    void operator()()
    {
        cout << "Hritik chouhan" << endl;
    }
};
int32_t main()
{
    // Funtion overloading
    //  show s;
    //  s.abc();

    // Operator overloading
    show s;
    s();
}