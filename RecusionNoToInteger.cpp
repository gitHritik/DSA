#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
void CountDigit(int n, string arr[])
{
    if (n == 0)
    {
        return;
    }
    int lastdigit = n % 10;

    n = n / 10;
    CountDigit(n, arr);
    cout << arr[lastdigit] << " ";
}
int32_t main()
{
    int n;
    cin >> n;

    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    CountDigit(n, arr);
}