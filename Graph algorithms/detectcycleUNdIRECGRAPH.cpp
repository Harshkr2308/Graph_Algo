#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
// Harsh kumar
vector<int> g[N];
// vector < vector<int>> cc;
// vector<int> current_cc;
bool vis[N];
bool isLoopExits=false;
bool dfs(int vertex,int par)
{
    vis[vertex] = true;
   // current_cc.push_back(vertex);
    for (int child : g[vertex])
    {
        if (vis[child] && child==par)continue;
            if(vis[child] )return true;
       isLoopExits |= dfs(child,vertex);
    }
    return isLoopExits;
}
int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    isLoopExits=false;
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i]) continue;
       
        if(dfs(i,0))
        {
            isLoopExits=true;
            break;
        }
          
       cout<<isLoopExits<<endl;
    }
   

    return 0;
}