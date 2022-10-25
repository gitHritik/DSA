#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

class hritik
{
private:
    int password;

public:
    string name;

    int getMethod()
    {
        return password;
    }
    void setMethod(int p)
    {
        password = p;
    }
};

int main()
{

    hritik h;
    h.name = "Hritiks";
    h.setMethod(234234);
    cout << sizeof(h) << endl;
    ;
    cout << h.name << endl;
    cout << h.getMethod() << endl;

    hritik *b = new hritik;
    b->name = "Hritiks";
    b->setMethod(234234);
    cout << sizeof(*b) << endl;
    ;
    cout << b->getMethod() << endl;
    cout << b->name << endl;
}