#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

class A
{
public:
    void abc()
    {
        cout << "A" << endl;
    }
};

class B
{

public:
    void abc()
    {
        cout << "B" << endl;
    }
};

class C : public A, public B
{
};
int32_t main()
{
    C d;
    d.A::abc();
    d.B::abc();
}