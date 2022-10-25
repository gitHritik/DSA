#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> nums, vector<int> output, int index, vector<int> &ans)
{
    if (index >= nums.size())
    {
        ans.push_back(output);
        return;
    }

    // exclude
    solve(nums, output, index + 1, ans);

    // include
    int element = nums[index];
    output.push_back(element);
}
int32_t main()
{

    vector<int> nums = {1, 2, 3};
    vector<int> ans;
    vector<int> output;
    int index = 0;

    solve(nums, output, index, ans);

    for (int i = 0; i < ans.size() - 1; i++)
    {
        cout << ans.at();
    }
}