#include <bits/stdc++.h>
using namespace std;

bool dfscheck(int node, vector<vector<int>> adj, int color[])
{

    if (color[node] == -1)
    {
        color[node] = 1;
    }
    for (auto it : adj[node])
    {
        if (color[it] == -1)
        {
            color[it] = 1 - color[node];
            if (!dfscheck(it, adj, color))
                return false;
        }
        else if (color[it] == color[node])
            return false;
    }

    return true;
}
bool checkbipartite(vector<vector<int>> adj, int n)
{
    int color[n];
    memset(color, -1, sizeof(color));
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!dfscheck(i, adj, color))
                return false;
        }
    }
    return true;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    if (checkbipartite(adj, n))
        cout << "YES" << endl;
    else
        cout << "no" << endl;
    return 0;
}