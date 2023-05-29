#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template <typename T>
#define rep(i, a, b) for (int i = a; i < b; i++)

class graph
{
public:
    unordered_map<T, list<T>> adj;

    void addEdges(T u, T v, bool direction)
    {
        // 0-> direction is undirected
        // 1-> direction is directed

        adj[u].push_back(v);

        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printGraph()
    {

        for (auto i : adj)
        {
            cout << i.first << "->";

            for (int j : i.second)
            {
                cout << j << ",";
            }

            cout << endl;
        }
    }
};
int32_t main()
{

    int n;
    cin >> n;
    int m;
    cin >> m;
    graph<int> g;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdges(u, v, 0);
    }

    g.printGraph();
}