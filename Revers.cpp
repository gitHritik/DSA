#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int32_t main()
{
    int n;
    cin >> n;
    int reverse = 0;
    while (n)
    {
        int lastdigit = n % 10;
        reverse = reverse * 10 + lastdigit;
        n /= 10;
    }
    cout << reverse;
}