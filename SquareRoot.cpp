#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long int root(long long int n)
{
    int s = 0;
    int e = n;
    long long int mid = s + (e - s) / 2;
    long long int ans = -1;
    while (s <= e)
    {
        long long int square = mid * mid;
        if (square == n)
            return mid;

        if (square < n)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

double nextNo(int n, int total, int temp)
{
    double ans = temp;
    double fact = 1;

    for (int i = 0; i < total; i++)
    {
        fact = fact / 10;
        for (
            double j = ans; j * j < n; j = j + fact)
        {
            ans = j;
        }
    }
    return ans;
}
int32_t main()
{
    int n = 27;
    long long int ans = root(n);

    cout << nextNo(n, 3, ans);
}
