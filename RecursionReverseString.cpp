#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
void reverse(string &s, int i, int j)
{

    if (i > j)

        return;

    swap(s[i], s[j]);
    i++;
    j--;

    reverse(s, i, j);
}
int32_t main()
{
    string s = "hritik";

    reverse(s, 0, s.length() - 1);
    cout << s;
}