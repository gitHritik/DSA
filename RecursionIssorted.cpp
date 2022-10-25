#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
bool isSorted(int *arr, int n)
{
    // base case
    if (n == 0 || n == 1)
    {
        return true;
    }

    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        bool ans = isSorted(arr + 1, n - 1);
        return ans;
    }
}
int32_t main()
{
    int arr[] = {1, 4, 3, 4, 5, 6};

    int ans = isSorted(arr, 6);

    if (ans)
    {
        cout << "sorted";
    }
    else
    {
        cout << "not sorted";
    }
}