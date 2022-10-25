#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int32_t main()
{
    int arr[10] = {1, 23, 4, 3, 0};

    cout << sizeof(arr) << endl;    // size of whole array
    cout << sizeof(arr[0]) << endl; // size of 1 integer

    cout << arr << endl;
    cout << (*arr) << endl;
    cout << (*arr + 1) << endl;
    cout << *arr + 1 << endl;
    cout << *(arr + 1) << endl;
    cout << &arr << endl;

    int *ptr = &arr[0];
    cout << ptr << endl;
    cout << ptr + 1 << endl;
    ptr = ptr + 1;
    cout << *ptr << endl;
    cout << *(ptr + 1) << endl;

    int i = 2;
    cout << i[arr] << " " << *(i + arr) << endl;
    cout << i[arr] << " " << (i + arr) << endl;
}