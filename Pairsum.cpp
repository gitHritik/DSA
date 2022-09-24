#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int pairsum(int arr[], int n, int sum)

{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == sum)
            {
                   vector<int> temp;
                   temp.push_back(min(arr[i],arr[j]));
                   temp.push_back(max(arr[i],arr[j]));
                   ans.push_back(temp);

            
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