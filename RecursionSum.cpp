#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int sumOfArray(int *arr, int n)
{

    print(arr, n);

    if (n <= 0)
    {
        return 0;
    }
    int sum = arr[0];

    cout << sum << endl;

    return sum + sumOfArray(arr + 1, n - 1);
}
int32_t main()
{
    int arr[] = {1, 2, 3, 4, 5, 7};

    int ans = sumOfArray(arr, 6);

    cout << ans << endl;
}