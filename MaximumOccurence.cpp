#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
char occurence(string s)
{
    int ch[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        int number = 0;
        number = s[i] - 'a';
        ch[number]++;
    }
    int maxi = -1;
    int ans;
    for (int i = 0; i < 26; i++)
    {
        if (maxi < ch[i])
        {
            ans = i;
            maxi = ch[i];
        }
    }
    return ans + 'a';
}
int32_t main()
{

    string s;
    cin >> s;
    char ans = occurence(s);
    cout << ans;
}