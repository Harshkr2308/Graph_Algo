#include <bits/stdc++.h>
using namespace std;

// Harsh kumar
struct node
{
    int parent;
    int rank;
};
vector<node>dsuf;
int find(int v)
{
    if(dsuf[v].parent==-1)
    return v;
    return dsuf[v].parent=find(dsuf[v].parent);//path compression
}

void union_op(int fromp,int top)
{
    if(dsuf[fromp].rank>dsuf[top].rank)
    dsuf[top].parent=fromp;
    else if(dsuf[fromp].rank<dsuf[top].rank)
    dsuf[fromp].parent=top;
    else{
        dsuf[fromp].parent=top; //both have same rank anyone made Aparent
        dsuf[top].rank+=1;
    }
}
bool iscycle(vector<pair<int,int>> &edge_list)
{
  for(auto u:edge_list)
  {
    int fromp=find(u.first);
    int top=find(u.second);
    if(fromp==top)
    return true;
    union_op(fromp,top);
  }  
  return false;
}
int main()
{
int  E,V;
cin>>E>>V;
dsuf.resize(V);
for(int i=0;i<V;i++)
{
    dsuf[i].parent=-1;
    dsuf[i].rank=0;
}
vector<pair<int,int>> edge_list;
for(int i=0;i<E;i++)
{
    int from,to;
    cin>>from>>to;
    edge_list.push_back({from,to});
}
if(iscycle(edge_list))
cout<<"true"<<endl;
else
cout<<"false"<<endl;
    return 0;
}