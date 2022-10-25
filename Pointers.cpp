#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int32_t main()
{
    int i = 234;
    int *p = &i;

    cout << "Value of i" << *p << endl;
    cout << "address of i" << p << endl;

    (*p)++;
    cout << "Value of i" << *p << endl;
    cout << "address of i" << p << endl;

    p++;
    cout << "Value of i" << *p << endl;
    cout << "address of i" << p << endl;

    cout << &i << endl;
}