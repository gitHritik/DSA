#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
bool isvalid(int arr[], int n, int m, int mid)
{
    int studentCount = 1;
    int pageCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (pageCount + arr[i] <= mid)
        { // 0+10 <=56
            pageCount += arr[i];
        }
        else
        {
            studentCount++;
            if (studentCount > m || arr[i] > mid)
            {
                return false;
            }
            pageCount = arr[i];
        }
    }
    return true;
}
int bookAllocation(int arr[], int n, int m)
{
    int s = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int e = sum;
    int mid = s + (e - s) / 2;
    int ans;
    while (s <= e)
    {
        if (isvalid(arr, n, m, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int32_t main()
{
    int arr[] = {10, 20, 30, 40};
    int n = 4;
    int m = 2;

    int ans = bookAllocation(arr, n, m);
    cout << ans;
}