#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int check(int arr[], int n)
{
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            count++;
        }
    }
    if (arr[n - 1] > arr[0])
    {
        count++;
    }

    return count;
}
int32_t main()
{
    int arr[] = {3, 4, 5, 1, 2};

    int ans = check(arr, 5);

    if (ans <= 1)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
}