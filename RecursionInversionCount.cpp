#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
// second approach without merge sort

int countInvesion(int *arr, int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                count++;
            }
        }
    }
    return count;
}

// First approach with merge sort
int merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;
    int count = 0;

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
            count += len1 - index1;
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
    return count;
}

int mergeSort(int *arr, int s, int e)
{
    int count = 0;

    // base case
    if (s < e)
    {

        int mid = (s + e) / 2;
        // left array
        count += mergeSort(arr, s, mid);

        // right array
        count += mergeSort(arr, mid + 1, e);

        // merging
        count += merge(arr, s, e);
    }

    return count;
}
int32_t main()
{
    int arr[] = {2, 1, 6, 3, 4};

    int n = 5;

    cout << countInvesion(arr, 5);

    // cout << mergeSort(arr, 0, n - 1);
}