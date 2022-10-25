#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int power(int n, int b)
{
    if (b == 0)
    {
        return 1;
    }
    int ans = power(n, b - 1);
    return n * ans;
}
int32_t main()
{
    int n;
    cin >> n;
    int b;
    cin >> b;

    int ans = power(n, b);
    cout << ans;
}