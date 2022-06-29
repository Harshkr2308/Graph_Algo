#include <bits/stdc++.h>
using namespace std;

// Harsh kumar
bool checkcycle(int node, vector<int> adj[], int vis[], int dfsvis[])
{
    vis[node] = 1;
    dfsvis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (checkcycle(it, adj, vis, dfsvis))
                return true;
        }
        else if (dfsvis[it])
            return true;
    }
    dfsvis[node] = 0;
    return false;
}
bool iscycle(int n,vector<int>adj[])
{
    int vis[n],dfsvis[n];
    memset(vis,0,sizeof(vis));
    memset(dfsvis,0,sizeof(dfsvis));
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            if(checkcycle(i,adj,vis,dfsvis))
            return true;
        }
    }
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int>adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
    }
    if (iscycle(n, adj))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    return 0;
}