#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
void reverse(int ans[], int k)
{
    int s = 0;
    int e = k - 1;
    while (s <= e)
    {
        swap(ans[s++], ans[e--]);
    }
}
void addArrays(int a[], int n, int b[], int m)
{
    int i = n - 1;
    int j = m - 1;
    int carry = 0;
    int k = 0;
    int ans[k];
    while (i >= 0 && j >= 0)
    {
        int sum = a[i] + b[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans[k] = sum;
        i--;
        j--;
        k++;
    }

    while (i >= 0)
    {
        int sum = a[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans[k] = sum;
        i--;
        k++;
    }
    while (j >= 0)
    {
        int sum = b[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans[k] = sum;
        j--;
        k++;
    }
    while (carry != 0)
    {
        int sum = carry;
        carry = sum / 10;
        sum = sum % 10;
        ans[k] = sum;
    }
    reverse(ans, k);

    for (int i = 0; i < k; i++)
    {
        cout << ans[i] << " ";
    }
}

int32_t main()
{
    int a[4] = {1, 2, 3, 4};
    int b[1] = {6};

    addArrays(a, 4, b, 1);
}