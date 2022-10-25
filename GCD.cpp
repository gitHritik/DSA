#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }
    int ans = 0;
    if (a > b)
    {

        ans = gcd(a - b, b);
    }
    else
    {
        ans = gcd(b - a, a);
    }

    return ans;
}
int32_t main()
{
    int a, b;
    cin >> a >> b;

    cout << gcd(a, b);
}