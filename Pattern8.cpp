#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int32_t main()
{
    int n;
    cin >> n;
    int i = 1;
    while (i <= n)
    {
        int j = i;
        while (j >= 1)
        {
            cout << j << " ";
            j--;
        }
        cout << endl;
        i++;
    }
}