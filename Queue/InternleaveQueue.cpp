#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
void interLeaveQueue(queue<int> &q)
{
    stack<int> s;
    int n = q.size() / 2;

    for (int i = 0; i < n; i++)
    {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        q.push(val);
    }

    for (int i = 0; i < n; i++)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    for (int i = 0; i < n; i++)
    {
        int val = q.front();
        q.pop();
        s.push(val);
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}
int32_t main()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);

    interLeaveQueue(q);
    cout << q.size() << endl;
    for (int i = 0; i < q.size(); i++)
    {
        cout << q.front() << " ";
        q.pop();
    }
}