#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int partition(int *arr, int s, int e)
{
    // First element is pivot;
    int pivot = arr[s];

    // store the count that is less then pivot
    int count = 0;

    for (int i = s + 1; i < e; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }

    // store the index of pivot
    int minIndex = s + count;
    swap(arr[minIndex], arr[s]);

    // now in left the small element then pivot and in right gretar element then pivot

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

    if (s >= e)
    {
        return;
    }

    // One pivot element will come that placed on right place
    int pi = partition(arr, s, e);

    // Other half partiton
    quickSort(arr, s, pi - 1);

    // Other right partiton
    quickSort(arr, pi + 1, e);
}

int32_t main()
{
    int arr[] = {2, 1, 6, 3, 4, 0, 56, 67};
    int n = 8;

    quickSort(arr, 0, n - 1);
    rep(i, 0, n)
    {
        cout << arr[i] << " ";
    }
}