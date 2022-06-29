#include <bits/stdc++.h>
using namespace std;

// Harsh kumar
bool checkforcycle(int s, int n, vector<vector<int>> adj, vector<int> &vis)
{
    queue<pair<int, int>> q;
    vis[s] = true;
    q.push({s, -1});
    while (!q.empty())
    {
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = true;
                q.push({it, node});
            }
            else if (par != it)
                return true;
        }
    }
    return false;
}
bool iscycle(int n,vector<vector<int>> adj)
{
    vector<int>vis(n+1,0);
    for(int i=0;i<n+1;i++)
    {
        if(!vis[i])
        {
            if(checkforcycle(i,n,adj,vis))
            return true;
        }
    
    }
    return false;
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
    if (iscycle)
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}