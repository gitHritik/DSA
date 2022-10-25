#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
bool LinearSearch(int arr[], int n, int k)
{
    // base case
    if (n == 0)
    {
        return false;
    }

    if (arr[0] == k)
    {
        return true;
    }
    else
    {
        int remain = LinearSearch(arr + 1, n - 1, k);
        return remain;
    }
}
int32_t main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};

    int key = 3;

    int ans = LinearSearch(arr, 6, key);

    if (ans)
    {
        cout << "Present";
    }
    else
    {
        cout << "Absent";
    }
}