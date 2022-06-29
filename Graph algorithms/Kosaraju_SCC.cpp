#include <bits/stdc++.h>
using namespace std;

// Harsh kumar
unordered_map<int, vector<int>> adj, rev;
void dfs1(int i, vector<bool> &vis, stack<int> &st)
{
    vis[i] = true;
    for (int j : adj[i])
    {
        if (vis[j] == false)
            dfs1(j, vis, st);
    }
    st.push(i);
}
void reverse(int v)
{
    for (int i = 0; i < v; i++)
    {
        for (int j : adj[i])
            rev[j].push_back(i);
    }
}
void dfs2(int i, vector<bool> &vis)
{
    cout << i << " ";
    vis[i] = true;
    for (int j : rev[i])
    {
        if (!vis[j])
            dfs2(j, vis);
    }
}
void findSCC(int  v)
{
    stack<int> st;
    vector<bool> vis(v, false);
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
            dfs1(i, vis, st);
    }
    reverse(v);
    for (int i = 0; i < v; i++)
    {
        vis[i] = false;
    }
    cout << "strongly connected component are:\n";
    while (!st.empty())
    {
        int curr = st.top();
        st.pop();
        if (vis[curr] == false)
        {
            dfs2(curr, vis);
            cout << "\n";
        }
    }
}

int main()
{
    int v,e;
    cin>>v>>e;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    findSCC(v);
   
    return 0;
}
