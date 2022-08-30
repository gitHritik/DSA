#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int32_t main()
{
    int n;
    cin >> n;     // n = 5
    int m = n;    // m = 5 binary 0101
    int mask = 0; // mask as bit 00000000
    int ans = 0;
    if (n == 0)
    { // n is already as 0 then output will be reverse of it like 1
        cout << 1;
    }
    while (m != 0)
    {
        // 00000000///
        mask = (mask << 1) | 1; // the mask will be left shift and becuase of or with 1
        // it become
        m = m >> 1; // 00000000101 righ shift until it become zero
    }

    //~n = complement of n = 111111111111010
    ans = (~n) & mask; // here it end with mask 00000000000111 so ans will be = 000000000000010
    cout << ans;
}