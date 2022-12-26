#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
bool isValidParenthesis(string expression)
{
    stack<char> s;

    for (int i = 0; i < expression.length(); i++)
    {
        int ch = expression[i];

        if (ch == '(' || ch == '[' || ch == '{')
        {
            s.push(ch);
        }
        else
        {
            if (!s.empty())
            {
                int top = s.top();
                if ((ch == ')' && top == '(') || (ch == ']' && top == '[') || (ch == '}' && top == '{'))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    if (s.empty())
    {
        return true;
    }

    return false;
}
int32_t main()
{

    string ans = "[()]{}{[()()]()}";

    if (isValidParenthesis(ans))
    {
        cout << "Balanced";
    }
    else
    {
        cout << "Unbalanced";
    }
}