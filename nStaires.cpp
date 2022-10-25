#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int countDistinctWays(int nStairs)
{
    if (nStairs < 0)
    {
        return 0;
    }
    if (nStairs == 0)
    {
        return 1;
    }

    return countDistinctWays(nStairs - 1) + countDistinctWays(nStairs - 2);
}
int32_t main()
{
    int n;
    cin >> n;
    cout << countDistinctWays(n);
}