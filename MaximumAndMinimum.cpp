#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

void Maximum(int arr[], int n)
{
    int smallest = arr[0];
    int largest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (largest < arr[i])
        {
            largest = arr[i];
        }
        if (smallest > arr[i])
        {
            smallest = arr[i];
        }
    }
    cout << "Maximum is " << largest << " "
         << "Minimum is " << smallest;
}

int32_t main()
{
    int n;
    int arr[n];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Maximum(arr, n);
}
