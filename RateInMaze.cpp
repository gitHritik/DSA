#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
bool isSafe(int newx, int newy, vector<vector<int>> &m, int n, vector<vector<int>> visited)
{
    if ((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && visited[newx][newy] == 0 && m[newx][newy] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void solve(vector<vector<int>> &m, int x, int y, int n, vector<vector<int>> visited, string path)
{
    // base case
    if (x == n - 1 && y == n - 1)
    {
        cout << path << " ";
    }

    visited[x][y] = 1;

    // Down
    int newx = x + 1;
    int newy = y;
    if (isSafe(newx, newy, m, n, visited))
    {
        path.push_back('D');
        solve(m, newx, newy, n, visited, path);
        path.pop_back();
    }

    // UP
    newx = x - 1;
    newy = y;
    if (isSafe(newx, newy, m, n, visited))
    {
        path.push_back('U');
        solve(m, newx, newy, n, visited, path);
        path.pop_back();
    }

    // Right
    newx = x;
    newy = y + 1;
    if (isSafe(newx, newy, m, n, visited))
    {
        path.push_back('R');
        solve(m, newx, newy, n, visited, path);
        path.pop_back();
    }

    // Left
    newx = x;
    newy = y - 1;
    if (isSafe(newx, newy, m, n, visited))
    {
        path.push_back('L');
        solve(m, newx, newy, n, visited, path);
        ;
        path.pop_back();
    }

    visited[x][y] = 0;
}
int32_t main()
{
    vector<vector<int>> m = {{1, 0, 0, 0},
                             {1, 1, 0, 1},
                             {1, 1, 0, 0},
                             {0, 1, 1, 1}};

    int n = m.size();

    vector<vector<int>> visited = m;
    string path = "";
    if (m[0][0] == 0)
    {
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }
    int srcx = 0;
    int srcy = 0;

    solve(m, srcx, srcy, n, visited, path);
}