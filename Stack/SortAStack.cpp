#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
void solve(stack<int> &s, int x)
{
    // base case
    if (s.empty() || (s.top() < x))
    {
        s.push(x);
        return;
    }

    int top = s.top();
    s.pop();
    solve(s, x);
    s.push(top);
}
void sortStack(stack<int> &stack)
{
    if (stack.empty())
    {
        return;
    }
    int top = stack.top();
    stack.pop();
    sortStack(stack);

    solve(stack, top);
}
int32_t main()
{
    stack<int> s;

    s.push(5);
    s.push(-2);
    s.push(9);
    s.push(-7);
    s.push(3);

    sortStack(s);
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}