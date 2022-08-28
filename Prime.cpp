#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int32_t main()
{
    int n;
    cin >> n;
    if (n == 2 || n == 1)
    {
        cout << "Prime no";
    }

    if (n % 2 == 0)
    {
        cout << "Not prime";
    }
    else
    {
        cout << "Prime";
    }
}