#include <bits/stdc++.h>
using namespace std;

// Harsh kumar
bool checkforcycle(int node ,int parent,vector<int> &vis,vector<vector<int>> adj)
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(vis[it]==0)
        {
            if(checkforcycle(it,node,vis,adj))
            return true;
            else if(it!=parent)
            return true;
        }
    }
    return  false;
}
bool iscycle(int n,vector<vector<int>> adj)
{
    vector<int> vis(n+1,0);
    for(int i=0;i<=n;i++)
    {
        if(!vis[i])
        {
            if(checkforcycle(i,-1,vis,adj))
            return true;
        }
        return false;
    }
}
int main()
{
    int n ,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    if(iscycle(n,adj))
    cout<<"YES"<<endl;
    else
    cout<<"no"<<endl;

  
    return 0;
}