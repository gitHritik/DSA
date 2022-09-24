#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
char isLowercase(char ch)
{
    if (ch > 64 && ch < 97)
    {
        return ch;
    }
    else
    {
        char ans = ch + 'A' - 'a';
        return ans;
    }
}
int isLength(char name[])
{
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}
bool isPallindrome(char name[], int len)
{
    int s = 0;
    int e = len - 1;
    while (s <= e)
    {
        if ((name[s] > 31 && name[s] < 48) || (name[s] > 62 && name[s] < 65))
        {
            s++;
            continue;
        }
        if ((name[e] > 31 && name[e] < 48) || (name[e] > 62 && name[e] < 65))
        {

            e--;
            continue;
        }

        if (isLowercase(name[s]) != isLowercase(name[e]))
        {
            return false;
        }
        else
        {

            s++;
            e--;
        }
    }
    return true;
}

int32_t main()
{
    char name[20];
    cin >> name;
    int len = isLength(name);
    if (isPallindrome(name, len))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}