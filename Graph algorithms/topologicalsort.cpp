#include <bits/stdc++.h>
using namespace std;

// Harsh kumar
void findtoposort(int node, vector<int> &vis, vector<vector<int>> adj, stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            findtoposort(it, vis, adj, st);
        }
    }
    st.push(node);
}
vector<int> toposort(int n, vector<vector<int>> adj)
{
    stack<int> st;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            findtoposort(i, vis, adj, st);
        }
    }
    vector<int> topo;
    while (!st.empty())
    {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}


int main()
{
    int n, m;
    cin >> n >> m;
    vector < vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
    }
    vector<int> ans=toposort(n,adj);
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    return 0;
}