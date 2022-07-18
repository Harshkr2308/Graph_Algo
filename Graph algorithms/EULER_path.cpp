#include <bits/stdc++.h>
using namespace std;

// Harsh kumar
int v;
unordered_map<int,vector<int>>adj;
void dfs(int curr,vector<bool> &vis)
{
    vis[curr]=true;
    for(auto it:adj[curr])
    {
        if(!vis[it])
        dfs(it,vis);
    }
}
bool connected_graph()
{
    vector<bool> vis(v+1);
    int node=-1;
    for(int i=0;i<v;i++)
    {
        if(adj[i].size()>0)
        {
            node=i;
            break;
        }
    }
    if(node =-1)return true;
    dfs(node,vis);
    for(int i=0;i<v;i++)
    {
        if(vis[i]==false && adj[i].size()>0)return false;
    }
    return true;
}

int find_Euler()
{
if(!connected_graph())return 0;
int odd=0;
for(int i=0;i<v;i++)
{
    if(adj[i].size()&1)odd+=1;
}
if(odd>2)return 0;
return odd==0?2:1;
}
void findEuler_path()
{
    int ret=find_Euler();
    if(ret==0)
    cout<<"not euler"<<endl;
     if(ret==1)
     cout<<"semieuler"<<endl;
     else
     cout<<"euler"<<endl;

}
int main()
{
int  e;
cin>>v>>e;
for(int i=0;i<e;i++)
{
    int v,u;cin>>v>>u;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
findEuler_path();
    return 0;
}