#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;
int graph1[N][N];

vector<int> graph2[N];
int main()
{
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        // Adjacency matrix
        // O(N^2)
        // N != 10^5    || N<=10^3
        
        graph1[v1][v2]=1;
        graph1[v2][v1]=1;
      //  aDJACENCY LIST
      //O(N+m)
        graph2[v1].push_back(v2);
        graph2[v2].push_back(v1);
    }

}