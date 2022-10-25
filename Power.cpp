#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int power(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }

    return a * power(a, b - 1);
}
int32_t main()
{
    int a, b;
    cin >> a >> b;

    cout << power(a, b);
}