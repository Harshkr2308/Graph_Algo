#include <bits/stdc++.h>
using namespace std;

// Harsh kumar
struct Edge {
	int src;
	int dst;
	int wt;
};
void bellman(vector<Edge> &edge,int v,int e)
{
    int parent[v], cost_parent[v];
    vector<int> val(v, INT_MAX);
    parent[0] = -1;
    val[0] = 0;
    bool updated;
    for (int i = 0; i < v - 1; i++)
    {
        updated = false;
        for (int j = 0; j < e; j++)
        {
            int U = edge[j].src;
            int V = edge[j].dst;
            int wt = edge[j].wt;
            if (val[U] != INT_MAX && val[U] + wt < val[V])
            {
                val[V] = val[U] + wt;
                parent[V] = V;
                cost_parent[V] = val[V];
                updated = true;
            }
        }
        if (updated == false)
            break;
    }
    for (int j = 0; j < e; j++)
    {

        int U = edge[j].src;
        int V = edge[j].dst;
        int wt = edge[j].wt;
        if (val[U] != INT_MAX && val[U] + wt < val[V])
        {
            cout << "graph has -ve edge cycle" << endl;
            return;
        }
    }
    for(int  i=0;i<v;i++)
    {
        cout<<"u->v: "<<parent[i]<<"->"<<i<<" cost to reach "<<parent[i]<<"from source 0="<<val[i]<<"\n";
    }
}
int main()
{
    int e, v;
    cin >> e >> v;
    vector<Edge> edge(e);
    int src, dst, wt;
    for (int i = 0; i < e; i++)
    {
        cin >> src >> dst >> wt;
        edge[i].src = src;
        edge[i].dst = dst;
        edge[i].wt = wt;
    }
    bellman(edge,v,e);
    return 0;
}