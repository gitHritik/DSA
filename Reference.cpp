#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
void update(int &n)
{
    n++;
}
int32_t main()
{
    int n = 2;

    cout << "Before" << n << endl;
    update(n);
    cout << "After" << n;
}