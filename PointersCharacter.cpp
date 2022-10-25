#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int32_t main()
{
    char ch[7] = "hritik";

    cout << ch + 1 << endl;
    cout << *ch << endl;
    cout << &ch << endl;

    cout << (*ch + '1') << endl;
    cout << *(ch + 1) << endl;
    cout << *(&ch) << endl;
}