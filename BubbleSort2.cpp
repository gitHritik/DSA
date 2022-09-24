#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
void bubbleSort(int arr[], int n)
{
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
int32_t main()
{
    int arr[] = {2, 1, 6, 3, 4};

    bubbleSort(arr, 5);

    rep(i, 0, 5)
    {
        cout << arr[i] << " ";
    }
}