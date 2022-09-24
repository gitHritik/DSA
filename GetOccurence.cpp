#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
char getOccurecne(string s)
{
    int arr[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        int number = 0;
        number = s[i] - 'a';
        arr[number]++;
    }
    int maxi = -1;
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (maxi < arr[i])
        {
            ans = i;
            maxi = arr[i];
        }
    }
    char ch = ans + 'a';
    return ch;
}
int32_t main()
{
    string s;
    cin >> s;
    cout << getOccurecne(s);
}