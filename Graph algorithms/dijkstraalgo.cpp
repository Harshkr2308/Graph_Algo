#include <bits/stdc++.h>
using namespace std;

// Harsh kumar
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> g[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        g[u].push_back(make_pair(v, wt));
        g[v].push_back(make_pair(u, wt));
    }
    int source;
    cin >> source;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> disTo(n + 1, INT_MAX);
    disTo[source] = 0;
    pq.push(make_pair(0, source));
    while (!pq.empty())
    {
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        vector<pair<int, int>>::iterator it;
        for (auto it : g[prev])
        {
            int next = it.first;
            int nextdis = it.second;
            if (disTo[next] > disTo[prev] + nextdis)
            {
                disTo[next] = disTo[prev] + nextdis;
                pq.push(make_pair(disTo[next], next));
            }
        }
    }
    cout<<"the distance from  "<<source <<" are: \n";
    for(int i=1;i<n+1;i++)
    cout<<disTo[i]<<" " ;
    return 0;
}