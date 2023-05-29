#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int32_t main()
{
    priority_queue<char> heap;
    heap.push('a');
    heap.push('b');
    heap.push('c');
    heap.push('d');
    heap.push('b');
    heap.push('d');

    cout << heap.size() << endl;
    cout << heap.top() << endl;
}