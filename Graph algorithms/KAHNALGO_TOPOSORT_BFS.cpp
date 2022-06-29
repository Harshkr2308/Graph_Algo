#include <bits/stdc++.h>
using namespace std;

// Harsh kumar
vector<int> toposort(int n, vector<vector<int>> adj)
{
    queue<int> q;
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> todo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        todo.push_back(node);
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    return todo;
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
    }
    vector<int> ans = toposort(n, adj);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}