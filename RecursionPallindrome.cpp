#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

bool isPallindrome(string s, int i, int j)
{
    // base case
    if (i > j)
    {
        return true;
    }

    if (s[i] != s[j])
    {
        return false;
    }
    else
    {
        i++;
        j--;
        int ans = isPallindrome(s, i, j);
        return ans;
    }
}
int32_t main()
{
    string s = "Noon";

    if (isPallindrome(s, 0, s.length() - 1))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}