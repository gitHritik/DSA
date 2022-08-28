#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int32_t main()
{
    int n;
    cin >> n;
    int fact = 1;
    for (int i = 2; i <= n; i++)

        fact = fact * i;

    cout << fact;
}