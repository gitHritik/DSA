#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
int32_t main()
{
    unordered_map<string, int> m;

    // insert
    pair<string, int> p = make_pair("hritik", 1);
    m.insert(p);

    // sercond insert
    pair<string, int> pair2("singh", 2);
    m.insert(pair2);

    // third insert
    m["chouhan"] = 3;

    // check out the size

    cout << m.size() << endl;

    cout << m.at("chouhan") << endl;

    cout << m["singh"] << endl;

    // lets iterate in array
    unordered_map<string, int>::iterator it = m.begin();

    while (it != m.end())
    {
        cout << it->first << " " << it->second << endl;
        ;
        it++;
    }
}