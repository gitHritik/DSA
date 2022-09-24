#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int len(string s)
{
    int count = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        count++;
        i++;
    }
    return count;
}
int32_t main()
{
    string s;
    cin >> s;

    cout << len(s) << endl;
    cout << s.length() << endl;//Funtion to get length of string
}