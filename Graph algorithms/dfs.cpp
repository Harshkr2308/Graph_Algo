#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
// Harsh kumar
vector<int> g[N];
bool vis[N];

void dfs(int vertex)
{
    cout<<vertex<<endl;
    // if (vis[vertex])
    //     return;
    // vis[vertex] = true;
    /*take action on vertex after
    enetering the vertez */
    for (int child : g[vertex])
    {
       cout<<"par"<<vertex<<", child"<<child<<endl;
       if(vis[child])continue;
        /*take action on child before
          entering the child node*/
        dfs(child);
        /*take action on child
        after exiting the child node
         */
    }
    /*take action on vertex before
    entering the vertex*/
    //return isLoopExits;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    //dfs(n);

    return 0;
}