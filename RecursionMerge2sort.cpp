#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

void merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;

    // len of half array 3 - 0 + 1 = 4
    int len1 = mid - s + 1;

    // len of righ half 7 - 3 = 4
    int len2 = e - mid;

    int *arr1 = new int[len1];
    int *arr2 = new int[len2];

    // copy left half
    int k = s;

    for (int i = 0; i < len1; i++)
    {
        arr1[i] = arr[k++];
    }

    // copy right half
    k = mid + 1;

    for (int i = 0; i < len2; i++)
    {
        arr2[i] = arr[k++];
    }

    int index1 = 0;
    int index2 = 0;
    k = s;
    while (index1 < len1 && index2 < len2)
    {
        if (arr1[index1] < arr2[index2])
        {
            arr[k++] = arr1[index1++];
        }
        else
        {
            arr[k++] = arr2[index2++];
        }
    }

    while (index1 < len1)
    {
        arr[k++] = arr1[index1++];
    }
    while (index2 < len2)
    {
        arr[k++] = arr2[index2++];
    }
}

void mergeSort(int *arr, int s, int e)
{

    // base case
    if (s >= e)
    {
        return;
    }

    int mid = (s + e) / 2;
    // left array
    mergeSort(arr, s, mid);

    // right array
    mergeSort(arr, mid + 1, e);

    // merging
    merge(arr, s, e);
}
int32_t main()
{
    int arr[] = {2, 1, 6, 3, 4};

    int n = 5;

    mergeSort(arr, 0, n - 1);

    rep(i, 0, n)
    {
        cout << arr[i] << " ";
    }
}