#include <bits/stdc++.h>
using namespace std;

// Harsh kumar
unordered_map<int, vector<int>> adj;
void dfs(int u, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<pair<int, int>> &bridge)
{
    static int time = 0;
    disc[u] = low[u] = time;
    time++;
    for (auto v : adj[u])
    {
        if (disc[v] == -1)
        {
            parent[v] = u;
            dfs(v, disc, low, parent, bridge);
            low[u] = min(low[u], low[v]);

            if (low[v] > disc[u])
                bridge.push_back({u, v});
        }
        else if (v != parent[u])
        {
            low[u] = min(low[u], disc[v]);
        }
    }
}
void findbridge(int v)
{
    vector<int> disc(v, -1), low(v, -1), parent(v, -1);
    vector<pair<int, int>> bridge;
    for (int i = 0; i < v; i++)
    {
        if (disc[i] == -1)
        {
            dfs(i, disc, low, parent, bridge);
        }
        cout << "bridge are: \n";
        for (auto it : bridge)
        {
            cout << it.first << " ---> " << it.second << endl;
        }
    }
}
int main()
{

    int v = 5;
    adj[0].push_back(2);
    adj[2].push_back(0);
    adj[0].push_back(3);
    adj[3].push_back(2);
    adj[1].push_back(2);
    adj[0].push_back(1);
    adj[2].push_back(1);
    adj[1].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);
    findbridge(v);
    return 0;
}