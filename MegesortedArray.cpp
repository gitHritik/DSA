#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
void merge(int arr1[], int n, int arr2[], int m)
{
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            arr1[i] = arr2[j++];
        }
    }
    while(i<n){
        if(arr[i] == 0){
            arr[i] = arr[j];
            j++;                               5mnm
        }
    }

    while (j < m)
    {
        arr1[i++] = arr2[j++];
    }
}

void print(int arr3[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr3[i] << " ";
    }
}
int32_t main()
{
    int arr1[6] = {1, 3, 5, 0, 0, 0};
    int arr2[3] = {2, 4, 6};

    merge(arr1, 6, arr2, 3);

    print(arr1, 6);
}