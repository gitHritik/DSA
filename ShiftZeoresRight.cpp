#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
void shift(vector<int> &arr)
{
    int i = 0;
    for (int j = 0; j < arr.size(); j++)
    {
        if (arr[j] != 0)
        {
            swap(arr[j], arr[i]);
            i++;
        }
    }
}

void print(vector<int> &ans)
{
    for (auto i : ans)
    {
        cout << i << " ";
    }
}
int32_t main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(0);
    v.push_back(12);
    v.push_back(0);
    v.push_back(8);

    shift(v);
    print(v);
}