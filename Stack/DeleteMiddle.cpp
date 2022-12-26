#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

void solve(stack<int> &s, int count, int n)
{
    if (count == n / 2)
    {
        s.pop();
        return;
    }

    int top = s.top();
    s.pop();
    solve(s, count + 1, n);
    s.push(top);
}

void deleteMiddleElement(stack<int> &s)
{
    int n = s.size();
    int count = 0;

    solve(s, count, n);
}
int32_t main()
{

    stack<int> s;

    s.push(14);
    s.push(12);
    s.push(2);
    s.push(92);
    s.push(1);

    // while (!s.empty())
    // {
    //     cout << s.top() << endl;
    //     s.pop();
    // }

    deleteMiddleElement(s);

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
}