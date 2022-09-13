#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i; // here we are assumign that i is minimum
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex]) // compare is there anyone else is min then i
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]); // swapping with starting element and the the element which is minimu in all of them
    }
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