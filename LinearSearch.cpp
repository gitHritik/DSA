#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
bool search(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (key == arr[i])
        {
            return true;
        }
    }
    return false;
}
int32_t main()
{
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cin >> key;

    bool isTrue = search(arr, n, key);

    if (isTrue)
    {
        cout << "Key is present";
    }
    else
    {
        cout << "Key is not present";
    }
}