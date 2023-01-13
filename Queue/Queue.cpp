#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int32_t main()
{
    queue<int> q;

    q.push(11);
    q.push(1);
    q.push(17);

    cout << q.size() << endl;
    q.pop();
    cout << q.size() << endl;
}