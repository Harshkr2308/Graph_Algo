#include <bits/stdc++.h>
using namespace std;

// Harsh kumar
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    vector<int> parent(n, -1), key(n, INT_MAX);
    vector<bool> mstSet(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    parent[0] = -1;
    pq.push({0, 0});
    while (!pq.empty())
    {
        int a = pq.top().second;
        pq.pop();
        mstSet[a]=true;
        for(auto it:adj[a])
        {
            int x=it[0];
            int weight=it[1];
            if(mstSet[x]==false && weight<key[x])
            {
                key[x]=weight;
                pq.push({weight,x});
            }
        }
        
    }
    int sum=accumulate(key.begin(),key.end(),0);
        cout<<sum<<endl;
    return 0;
}