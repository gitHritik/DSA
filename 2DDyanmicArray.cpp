#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int32_t main()
{
    int row;
    cin >> row;
    int col;

    int **arr = new int *[row];
    for (int i = 0; i < row; i++)
    {
        cin >> col;
        arr[i] = new int[col];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << sizeof(arr);

    // Releasing memory
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }

    // deleting memory
    delete[] arr;
}