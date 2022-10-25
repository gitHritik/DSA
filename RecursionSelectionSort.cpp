#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
void selectionSort(int *arr, int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }
    for (int i = 0; i < n; i++)
    {
        int minIndex = i;
        if (arr[i + 1] < arr[minIndex])
        {
            minIndex = i + 1;
        }
        swap(arr[i], arr[minIndex]);
    }
    selectionSort(arr + 1, n - 1);
}
int32_t main()
{
    int arr[] = {3, 1, 5, 2, 10};
    selectionSort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}