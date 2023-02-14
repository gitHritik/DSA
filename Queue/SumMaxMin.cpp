#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

int solve(int *arr, int n, int k)
{
    deque<int> maxi;
    deque<int> mini;

    // addition

    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() && arr[maxi.front()] <= arr[i])
        {
            maxi.pop_front();
        }
        while (!mini.empty() && arr[mini.front()] >= arr[i])
        {
            mini.pop_front();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }

    int ans = 0;
    for (int i = k; i < n; i++)
    {
        ans += arr[maxi.front()] + arr[mini.front()];

        // removal
        while (!maxi.empty() && i - maxi.front() >= k)
        {
            maxi.pop_front();
        }
        while (!mini.empty() && i - mini.front() >= k)
        {
            mini.pop_front();
        }

        // addition
        while (!maxi.empty() && arr[maxi.front()] <= arr[i])
        {
            maxi.pop_front();
        }
        while (!mini.empty() && arr[mini.front()] >= arr[i])
        {
            mini.pop_front();
        }
        maxi.push_back(i);
        mini.push_back(i);
    }
    ans += arr[maxi.front()] + arr[mini.front()];
    return ans;
}
int32_t main()
{
    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;

    cout << solve(arr, 7, k) << endl;
}