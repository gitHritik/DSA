#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
string removeOccurence(string s, string part)
{

    while (s.length() != 0 && s.find(part) < s.length())
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}
int32_t main()
{
    string s;
    cin >> s;
    string part;
    cin >> part;

    string ans = removeOccurence(s, part);

    cout << ans;
}