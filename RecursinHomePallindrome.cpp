#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

bool isPallindrome(string s, int i)
{
    // base case

    int n = s.length();
    if (i > n - i - 1)
    {
        return true;
    }

    if (s[i] != s[n - i - 1])
    {
        return false;
    }
    else
    {
        int ans = isPallindrome(s, i + 1);
        return ans;
    }
}
int32_t main()
{
    string s = "bookoob";

    if (isPallindrome(s, 0))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}