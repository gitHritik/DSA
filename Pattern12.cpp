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
        int j = 1;
        int start = i;
        while (j <= n)
        {
            char ch = 'A' + start - 1;
            cout << ch << " ";
            start++;
            j++;
        }
        cout << endl;
        i++;
    }
}