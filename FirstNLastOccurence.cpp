#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int firstOccurence(int arr[], int n, int k)
{
    int s = 0;
    int e = n - 1;
    int mid = s + e / 2;
    int ans = 0;
    while (s <= e)
    {
        if (arr[mid] == k)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (arr[mid] > k)
        {
            e = mid - 1;
        }
        else if (arr[mid] < k)
        {
            s = mid + 1;
        }
        mid = s + e / 2;
    }
    return ans;
}
int lastOccurence(int arr[], int n, int k)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = 0;
    while (s <= e)
    {
        if (arr[mid] == k)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (arr[mid] > k)
        {
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
    int even[] = {1, 2, 3, 3, 3, 6};
    cout << firstOccurence(even, 6, 3);
    cout << lastOccurence(even, 6, 3);
}