#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int32_t main()
{
    string s = "hritik";

    stack<char> st;
    string ans = "";

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        st.push(ch);
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    cout << ans;
}