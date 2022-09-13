#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
void pairsum(int arr[], int n, int sum)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == sum)
            {
                int temp1 = min(arr[i], arr[j]);
                int temp2 = max(arr[i], arr[j]);

                sort(temp1.begin(), temp2.end);
                cout
                    << temp1 << " " << temp2 << endl;
                break;
            }
        }
    }
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
    int sum;
    cin >> sum;
    pairsum(arr, n, sum);
}