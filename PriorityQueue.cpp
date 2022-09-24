#include <iostream>
#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int32_t main()
{

    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;

    maxi.push(2);
    maxi.push(7);
    maxi.push(0);
    maxi.push(4);

    int n = maxi.size();

    rep(i, 0, n)
    {
        cout << maxi.top() << " ";
        maxi.pop();
    }
    cout << endl;

    mini.push(2);
    mini.push(7);
    mini.push(0);
    mini.push(4);

    int s = mini.size();

    rep(i, 0, s)
    {
        cout << mini.top() << " ";
        mini.pop();
    }
    cout << endl;
}