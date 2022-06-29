#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;
vector<pair<int,int>> graph3[N];
int graph1[N][N];
int main()
{
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
      // adjacency matrix
        graph1[v1][v2]=wt;
        graph1[v2][v1]=wt;
      //adjacency list
        graph3[v1].push_back({v2,wt});
        graph3[v2].push_back({v1,wt});
    }
}