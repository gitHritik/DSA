#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int32_t main()
{
    int n;
    cin >> n;
    int ans = 0, i = 0;
    while (n)
    {
        int digit = n % 10;
        if (digit == 1)
        {

            ans = ans + pow(2, i);
        }
        n /= 10;
        i++;
    }
    cout << ans;
}