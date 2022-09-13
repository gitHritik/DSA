#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void pivot(int arr[], int n)
{
    int e = 0;
    int s = n - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
            e = mid;
        mid = s + (e - s) / 2;
    }
    cout << mid << " ";
}
int32_t main()
{
    int arr[] = {4, 5, 1, 2, 3};
    pivot(arr, 5);
}