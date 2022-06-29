#include <bits/stdc++.h>
using namespace std;

// Harsh kumar
void findtoposort(int node, int vis[], vector<pair<int, int>> adj[], stack<int> &st )
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it.first])
        {
            findtoposort(it.first, vis, adj, st);
        }
    }
    st.push(node);
}

void Shortestpath(int src, int n, vector<pair<int, int>> adj[])
{
    stack<int> st;
    int vis[n] = {0};
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            findtoposort(i, vis, adj, st);
    }
    int dis[n];
    for (int i = 0; i < n; i++)
    {
        dis[i] = 1e9;
    }
    dis[src] = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (dis[node] != INFINITY)
        {
            for (auto it : adj[node])
            {
                if (dis[node] + it.second < dis[it.first])
                {
                    dis[it.first = dis[node] + it.second];
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        dis[i]==1e9?cout<<"INF  ":cout<<dis[i]<<" ";
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    Shortestpath(0,n,adj);
    return 0;
}