#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
string addition(string s)
{
    string temp = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else
        {
            temp.push_back(s[i]);
        }
    }
    
    return temp;
}
int32_t main()
{
    string s = 0;
    cin >> getline(s, 100);

    string ans = addition(s);
    for (int i = 0; i < ans.length(); i++)
    {
        cout << ans[i];
    }
}