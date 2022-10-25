#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
// void sum(int *p)
// {
//     p = p + 1;
// }
// void update(int *p)
// {
//     *p = *p + 1;
// }

int sum(int *arr, int n)
{
    cout << sizeof(arr) << endl;
    int sum = 0;
    rep(i, 0, n)
    {
        sum += arr[i];
    }
    return sum;
}
int32_t main()
{
    int temp = 10;

    int *p = &temp;

    // cout << "Before -->" << p << endl;
    // sum(p);
    // cout << "After -->" << p << endl;

    // cout << "Before -->" << *p << endl;
    // update(p);
    // cout << "After -->" << *p << endl;

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << sum(arr + 6, 4);

    cout << sizeof(*p) << endl;
}
