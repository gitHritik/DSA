#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

void setBits(int a, int b)
{

    int count = 0;

    while (a != 0 || b != 0)
    {
        int bit = a & 1;
        a = a >> 1;
        int hi = -b & 1;
        b = b >> 1;
        if (bit == 1)
        {
            count++;
        }

        if (hi == 1)
        {
            count++;
        }
    }
    cout << count << endl;
}
int32_t main()
{
    int a, b;
    cin >> a >> b;
    setBits(a, b);
}
