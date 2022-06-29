#include <bits/stdc++.h>
using namespace std;

// Harsh kumar
struct node {
	int parent;
	int rank;
};
struct Edge {
	int src;
	int dst;
	int wt;
};

vector<node> dsuf;
vector<Edge> mst;
//FIND operation
int find(int v)
{
	if(dsuf[v].parent==-1)
		return v;
	return dsuf[v].parent=find(dsuf[v].parent);	//Path Compression
}

void union_op(int fromP,int toP)
{
	//fromP = find(fromP);
	//toP = find(toP);

	//UNION by RANK
	if(dsuf[fromP].rank > dsuf[toP].rank)	//fromP has higher rank
		dsuf[toP].parent = fromP;
	else if(dsuf[fromP].rank < dsuf[toP].rank)	//toP has higher rank
		dsuf[fromP].parent = toP;
	else
	{
		//Both have same rank and so anyone can be made as parent
		dsuf[fromP].parent = toP;
		dsuf[toP].rank +=1;		//Increase rank of parent
	}
}

bool comparator(Edge a,Edge b)
{
	return a.wt < b.wt;
}
void Kruskals(vector<Edge> &edge_list, int v, int e)
{
    sort(edge_list.begin(), edge_list.end(), comparator);
    int i = 0, j = 0;
    while (i < v - 1 && j < e)
    {
        int fromp = find(edge_list[j].src);
        int top = find(edge_list[j].dst);

        if (fromp == top)
        {
            j++;
            continue;
        }
        union_op(fromp, top);
        mst.push_back(edge_list[j]);
        i++;
    }
}
void printmst(vector<Edge> &mst)
{
    cout << "mst formed is\n";
    for (auto p : mst)
    {
        cout << "src: " << p.src << " dst: " << p.dst << " wt: " << p.wt << "\n";
    }
}
int main()
{
    int e, v;
    cin >> e >> v;
    dsuf.resize(v);
    for (int i = 0; i < v; i++)
    {
        dsuf[i].parent = -1;
        dsuf[i].rank = 0;
    }
    vector<Edge> edge_list;
    Edge temp;
    for (int i = 0; i < e; i++)
    {
        int from, to, wt;
        cin >> from >> to >> wt;
        temp.src = from;
        temp.dst = to;
        temp.wt = wt;
        edge_list.push_back(temp);
    }
    Kruskals(edge_list, v, e);
    printmst(mst);
    return 0;
}
/*
input
10 6
0 1 1
1 3 1
2 4 1 
2 3 2
3 4 2
1 2 3
1 4 3
4 5 3
3 5 4
output
mst formed is
src: 0 dst: 1 wt: 1
src: 1 dst: 3 wt: 1
src: 2 dst: 4 wt: 1
src: 0 dst: 2 wt: 2
src: 4 dst: 5 wt: 3
*/