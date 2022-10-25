#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int partition(int *arr, int s, int e)
{
    int pivot = arr[s];
    int count = 0;
    for (int i = s; i < e; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    int minIndex = s + count;
    swap(arr[minIndex], arr[s]);

    int i = s;
    int j = e;
    while (i < minIndex && j > minIndex)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < minIndex && j > minIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return minIndex;
}
void quickSort(int *arr, int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }

    int pi = partition(arr, s, e);
    quickSort(arr, s, pi - 1);
    quickSort(arr, pi + 1, e);
}
int32_t main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}