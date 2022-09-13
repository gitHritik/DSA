#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int32_t main()
{
    int totalamout;
    cin >> totalamout;
    int n = totalamout;
    int amount = 0;

    switch (true)
    {
    case true:
        cout << totalamout / 100 << endl;
        amount = totalamout - (totalamout / 100) * 100;
        cout << amount / 50 << endl;
        amount = amount - (amount / 50) * 50;
        cout << amount / 20 << endl;
        amount = amount - (amount / 20) * 20;
        cout << amount / 1 << endl;
        break;

    default:
        cout << "Nothing go man";
        break;
    }
}