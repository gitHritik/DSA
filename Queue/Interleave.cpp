#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
void interLeaveQueue(queue<int> &q)
{
    stack<int> s;

    int k = q.size() / 2;
    for (int i = 0; i < k; i++)
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

    for (int i = 0; i < k; i++)
    {
        int top = q.front();
        q.pop();
        q.push(top);
    }
    for (int i = 0; i < k; i++)
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
        top = q.front();
        q.pop();
        q.push(top);
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
    q.push(19);
    q.push(20);

    interLeaveQueue(q);
    cout << q.size() << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }
}