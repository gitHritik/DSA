#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
void solve(stack<int> &s, int x)
{

    // base case
    if (s.empty())
    {
        s.push(x);
        return;
    }

    int top = s.top();
    s.pop();
    solve(s, x);
    s.push(top);
}
int32_t main()
{
    stack<int> s;

    s.push(14);
    s.push(12);
    s.push(2);
    s.push(92);
    s.push(1);

    solve(s, 6);

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}