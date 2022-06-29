#include <bits/stdc++.h>
using namespace std;

// Harsh kumar
void Shortestdistancebfs(vector<vector<int>> adj,int n,int src)
{
    int dis[n];
    queue<int>q;
    for (int i=0;i<n;i++)
    dis[i]=INT_MAX;
    q.push(src);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto it:adj[node])
        {
            if(dis[node]+1<dis[it])
            {
                dis[it]=dis[node]+1;
                q.push(it);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<dis[i]<<" ";
    }
}
int main()
{
    int n, m,src=0;
    cin >> n >> m;
    vector<vector<int>>adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    Shortestdistancebf(adj,n,0);
    return 0;
}