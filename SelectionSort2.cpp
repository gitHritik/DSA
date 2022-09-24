#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int mixi = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[mixi])
            {
                mixi = j;
            }
        }
        swap(arr[i], arr[mixi]);
    }
}
int32_t main()
{
    int arr[] = {2, 1, 6, 3, 4};

    selectionSort(arr, 5);

    rep(i, 0, 5)
    {
        cout << arr[i] << " ";
    }
}