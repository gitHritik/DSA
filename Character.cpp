#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int32_t main()
{
    char ch;
    cin >> ch;
    if (ch >= 97)
    {
        cout << "small";
    }
    else if (ch > 64 && ch < 91)
    {
        cout << "Capital";
    }
    else
    {
        cout << "Numeric";
    }
}