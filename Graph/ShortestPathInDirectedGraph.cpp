#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)

class Graph
{

public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);

        adj[u].push_back(p);
    }

    void print()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << "(" << j.first << "," << j.second << ")";
            }
            cout << endl;
        }
    }

    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &s)
    {

        visited[node] = 1;

        for (auto i : adj[node])
        {
            if (!visited[i.first])
            {
                dfs(i.first, visited, s);
            }
        }
        s.push(node);
    }

    void shortestPath(int src, vector<int> &ans, stack<int> &s)
    {

        ans[src] = 0;

        while (!s.empty())
        {
            int top = s.top();
            s.pop();

            if (ans[top] != INT_MAX)
            {
                for (auto i : adj[top])
                {

                    if (ans[top] + i.second < ans[i.first])
                    {
                        ans[i.first] = ans[top] + i.second;
                    }
                }
            }
        }
    }
};
int32_t main()
{
    Graph g;

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.print();

    // find topological sort

    unordered_map<int, bool> visited;
    stack<int> s;
    int n = 6;

    for (int i = 0; i < n; i++)
    {

        if (!visited[i])
        {
            g.dfs(i, visited, s);
        }
    }

    // find the shortest parth

    int src = 1;
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        ans[i] = INT_MAX;
    }

    g.shortestPath(src, ans, s);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}