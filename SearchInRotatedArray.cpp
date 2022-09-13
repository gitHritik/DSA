#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int binarySerach(int arr[], int s, int e, int key)
{
    int mid = s + (e - s) / 2;
    int ans = 0;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            break;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int getPivot(int arr[], int n)
{

    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[0] <= arr[mid])
        //
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}
int32_t main()
{
    int arr[] = {7, 9, 1, 2, 3};
    int k = 7;
    int ans = 0;
    int pivot = getPivot(arr, 5);
    if (k > arr[pivot] && k <= arr[5 - 1])
    {
        ans = binarySerach(arr, pivot, 5 - 1, 7);
    }
    else
    {
        ans = binarySerach(arr, 0, pivot - 1, 7);
    }
    cout << ans;
}