#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

void update(int **p2)
{

    // Pointing on address
    // p2 = p2 + 1; // same

    // *p2 = *p2 + 1; // p address increse by 4 bytes

    **p2 = **p2 + 1; // i value increase by 1
}
int32_t main()
{
    int i = 2;
    int *p = &i;

    int **p2 = &p;

    // cout << "Value of i" << endl;
    // cout << i << endl;
    // cout << *p << endl;
    // cout << **p2 << endl;

    // cout << "Address of i" << endl;
    // cout << &i << endl;
    // cout << p << endl;
    // cout << *p2 << endl;

    // cout << "Address of p" << endl;
    // cout << &p << endl;
    // cout << p2 << endl;

    // cout << "Values" << endl;
    // cout << p << endl;
    // cout << p2 << endl;

    // cout << "Address p2" << endl;
    // cout << &p2 << endl;

    cout << "Before" << endl;
    cout << i << endl;
    cout << p << endl;
    cout << p2 << endl;

    update(p2);
    cout << "After" << endl;
    cout << i << endl;
    cout << p << endl;
    cout << p2 << endl;
}