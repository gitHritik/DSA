#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int32_t main()
{
    set<int> s;
    s.insert(2);
    s.insert(9);
    s.insert(1);
    s.insert(10);

    for (auto i : s)
    {
        cout << i << " ";
    }

    cout << endl;
    set<int>::iterator itr = s.find(9);
    for (auto i = itr; i != s.end(); i++)
    {
        cout << *i << " ";
    }
}