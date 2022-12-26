#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
bool findRedundantBrackets(string &s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '+' || ch == '/' || ch == '*' || ch == '-')
        {
            st.push(ch);
        }
        else
        {
            bool redundent = true;
            if (ch == ')')
            {
                char top = st.top();
                while (st.top() != '(')
                {
                    if (top == '+' || top == '/' || top == '*' || top == '-')
                    {
                        redundent = false;
                    }
                    st.pop();
                }
                if (redundent == true)
                {
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}

int32_t main()
{
    string ans = "((a+v))";

    if (findRedundantBrackets(ans))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}