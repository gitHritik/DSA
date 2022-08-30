#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int32_t main()
{
    int n;
    cin >> n;
    bool ans = false;

    for (int i = 0; i < 31; i++)
    {
        if (pow(2, i) == n) // Here we are checking for all no's power that if there is any power is equal then we done it
        {
            ans = true;
        }
    }

    if (ans)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}