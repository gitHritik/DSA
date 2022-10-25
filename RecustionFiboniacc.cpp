#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}
int32_t main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << fib(i);
    }
}