#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int32_t main()
{
    int n;
    cin >> n;
    int ans = 0;
    while (n)
    {
        int lastdigit = n % 10;
        if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10))
        {
            cout << 0;
            break;
        }
        ans = ans * 10 + lastdigit;
        n /= 10;
    }
    cout << ans;
}