#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
void sums(int arr[][3], int n, int m)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sum += arr[i][j];
        }
        cout << sum << endl;
        sum = 0;
    }
}

int printMaxiRowIndex(int arr[][3], int n, int m)

{
    int maxi = -1;
    int rowIndex = -1;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum += arr[i][j];
        }
        if (maxi < sum)
        {
            maxi = sum;
            rowIndex = i;
        }
    }
    cout << maxi;
    return rowIndex;
}

void wavePrint(int arr[][3], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        if (i & 1)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        else
        {
            for (int j = 0; j < m; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
}
void spiralPrin(int arr[][3], int n, int m)
{
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = n - 1;
    int endCol = m - 1;
    int total = n * m;
    int count = 0;
    while (count < total)
    {
        // staring row
        for (int i = startingCol; count < total && i <= endCol; i++)
        {
            cout << arr[startingRow][i] << " ";
            count++;
        }
        startingRow++;

        // ending col
        for (int i = startingRow; count < total && i <= endingRow; i++)
        {
            cout << arr[i][endCol] << " ";
            count++;
        }
        endCol--;
        // endRow
        for (int i = endCol; count < total && i >= startingCol; i--)
        {
            cout << arr[endingRow][i] << " ";
            count++;
        }
        endingRow--;
        // startingcol
        for (int i = endingRow; count < total && i >= startingRow; i--)
        {
            cout << arr[i][startingCol] << " ";
            count++;
        }
        startingCol++;
    }
}
int32_t main()
{

    int arr[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    // sums(arr, 3, 3);
    // cout << endl;
    // cout << printMaxiRowIndex(arr, 3, 3);
    spiralPrin(arr, 3, 3);
}