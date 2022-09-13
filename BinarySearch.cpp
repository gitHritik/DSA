#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
void binarySearch(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    int mid = (s + e) / 2;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            cout << mid << endl;
            break;
        }
        if (key > arr[mid])
        {
            s = mid + 1;
        }
        else

        {
            e = mid - 1;
        }

        mid = (s + e) / 2;
    }
    if (arr[mid] != key)
    {
        cout << "-1" << endl;
    }
}
int32_t main()
{
    int even[] = {1, 2, 3, 4, 5, 6};
    int odd[] = {1, 2, 3, 4, 5};
    binarySearch(even, 6, 234);
    binarySearch(odd, 5, 145);
}