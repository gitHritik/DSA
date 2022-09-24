#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
void reversed(string &str)
{
    int s = 0;
    int e = str.length() - 1;

    while (s <= e)
    {
        swap(str[s], str[e]);
        s++;
        e--;
    }
}
int32_t main()
{
    string s;
    cin >> s;

    reversed(s);

    cout << s;
}