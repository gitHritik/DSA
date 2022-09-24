#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int isLength(char name[])
{
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}
void reverse(char name[], int len)
{
    int s = 0;
    int e = len - 1;
    while (s <= e)
    {
        swap(name[s++], name[e--]);
    }
}
int32_t main()
{
    char name[20];
    cin >> name;
    int len = isLength(name);
    reverse(name, len);
    cout << name;
}