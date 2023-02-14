#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
void reverseQ(queue<int> &q)
{
    stack<int> s;
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        s.push(top);
    }

    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        q.push(top);
    }
}
int32_t main()
{
    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(3);
    q.push(0);

    reverseQ(q);

    for (int i = 0; i < 7; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }
}