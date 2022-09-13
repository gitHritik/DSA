#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

bool isvalid(vector<int> &arr, int k, int mid)
{
    int cowsCount = 1;
    int lastPos = arr[0];
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] - lastPos >= mid)
        {
            cowsCount++;
            if (cowsCount == k)
            {
                return true;
            }
            lastPos = arr[i];
        }
    }
    return false;
}
int aggresiveCows(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());
    int s = 0;
    int maxi = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        maxi = max(maxi, arr[i]);
    }
    int e = maxi;
    int mid = s + (e - s) / 2;
    int ans;
    while (s <= e)
    {
        if (isvalid(arr, k, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int32_t main()
{
    vector<int> arr = {4, 2, 1, 3, 6};
    int k = 2;
    int ans = aggresiveCows(arr, k);
    cout << ans;
}