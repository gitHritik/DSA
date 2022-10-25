#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
void counting(int n)
{
    if (n == 0)
        return;
    cout << n << endl;
    ;
    counting(n - 1);
}
int32_t main()
{
    int n;
    cin >> n;

    counting(n);
}
