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
};

class newSHow : public show
{
public:
    void abc()
    {
        cout << "NO Hii only By" << endl;
    }
};
int32_t main()
{
    // Funtion overwriting
    newSHow s;
    s.abc();
}