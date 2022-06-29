#include <bits/stdc++.h>
using namespace std;

// Harsh kumar
const int N = 1e5 + 10;
multiset<int> sizes;
vector<int> parent(N);
vector<int> size(N);
void make(int v)
{
    parent[v] = v;
    size[v] = 1;
    sizes.insert(1);
}
int find(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}
void merge(int a, int b)
{
    sizes.erase(sizes.find(size[a]));
    sizes.erase(sizes.find(size[b]));

    sizes.insert(size[a] + size[b]);
}
void unionn(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
    }
    parent[b] = a;
    size[a] += size[b];
}
int main()
{
    
    int n, q;
    cin >> n >> q;

    for (int i = 0; i <= n; i++)
    {
        make(i);
    }
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        unionn(u, v);
        if (sizes.size() == 1)
            cout << 0 << endl;
        else
        {
            int mn = *sizes.begin();
            int mx = *(--sizes.end());
            cout << mx - mn << endl;
        }
    }
    // int ct = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     if (find(i) == i)
    //         ct++;
    // }
    // cout << ct << endl;
    return 0;
}