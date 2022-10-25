#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

class A
{
public:
    void speak()
    {
        cout << "A" << endl;
    }
};

class B : public A
{

public:
    void bark()
    {
        cout << "B" << endl;
    }
};

class C : public A
{

public:
    void says()
    {
        cout << "C" << endl;
    }
};
int32_t main()
{
    C d;
    d.speak();
    d.says();
    B b;
    b.speak();
    b.bark();
}