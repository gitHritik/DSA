#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
bool BinarySearch(int arr[], int s, int e, int key)
{
    // base case
    if (s > e)
    {
        return false;
    }

    int mid = (s + e) / 2;
    if (arr[mid] == key)
    {
        return true;
    }
    else if (arr[mid] < key)
    {
        return BinarySearch(arr, mid + 1, e, key);
    }
    else
    {
        return BinarySearch(arr, s, mid - 1, key);
    }
}
int32_t main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int key = 9;

    int ans = BinarySearch(arr, 0, 6, key);
    if (ans)
    {
        cout << "Present";
    }
    else
    {
        cout << "not present";
    }
}