#include <bits/stdc++.h>
using namespace std;

// Harsh kumar
unordered_map<int, vector<int>> adj;
void dfs(int u, vector<int> &disc, vector<int> &low, vector<bool> &presentinstack, stack<int> &st)
{
    static int time = 0;
    disc[u] = low[u] = time;
    time++;
    st.push(u);
    presentinstack[u] = true;

    for (int v : adj[u])
    {
        if (disc[v] == -1) // if v is not visited
        {
            dfs(v, disc, low, presentinstack, st);
            low[u] = min(low[u], low[v]);
        }
        // check for BE OR CE
        else if (presentinstack[v] == true) // backedge case
        {
            low[u] = min(low[u], disc[v]);
        }
    }
    if (low[u] == disc[u]) // u is head of SCC
    {
        cout << "SCC IS:  ";
        while (st.top() != u)
        {
            cout << st.top() << " ";
            presentinstack[st.top()] = false;
            st.pop();
        }
        cout << st.top() << "\n";
        presentinstack[st.top()] = false;
        st.pop();
    }
}
void findTarjan_SCC(int v)
{
    vector<int> disc(v, -1), low(v, -1);
    vector<bool> presentinstack(v, false);
    stack<int> st;
    for (int i = 0; i < v; i++)
    {
        if (disc[i] == -1)
            dfs(i, disc, low, presentinstack, st);
    }
}
int main()
{
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    findTarjan_SCC(v);

    return 0;
}