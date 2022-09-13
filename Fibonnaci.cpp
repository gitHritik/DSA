#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
void fib(int n)
{
    int n1 = 0;
    int n2 = 1;
    int nextterm = n1 + n2;
    cout << n1 << n2;
    for (int i = 2; i < n; i++)
    {
        cout << nextterm;
        n1 = n2;
        n2 = nextterm;
        nextterm = n1 + n2;
    }
}
int32_t main()
{
    int n;
    cin >> n;
    fib(n);
}