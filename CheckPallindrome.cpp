#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isalnum(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        return true; // that means a valid char as per our input
    }
    else
    {
        return false; // special or other characters
    }
}
char tolowercase(char ch)
{
    if (ch >= 'a' && ch <= 'z' || (ch >= 0 && ch <= 9))
        return ch;
    else
    {
        ch = ch - 'A' + 'a';
        return ch;
    }
}

bool checkPalindrome(string s)
{
    // Write your code here.
    int i = 0, j = s.length() - 1;
    while (i <= j)
    {
        if (isalnum(s[i]) == 0)
            i++;
        else if (isalnum(s[j]) == 0)
            j--;
        else if (tolowercase(s[i]) != tolowercase(s[j]))
            return false;
        else
        {
            i++;
            j--;
        }
    }
    return true;
}
int32_t main()
{
    string s;
    cin >> s;

    if (checkPalindrome(s))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No";
    }
}