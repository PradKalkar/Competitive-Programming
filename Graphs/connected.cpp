#include <bits/stdc++.h>
using namespace std;
#define N 10

vector<vector<int>> connected;
vector<int> adj[N];
bool visited[N];
vector<int> tmp;

void dfs(int v)
{
    if (visited[v]) return;
    visited[v] = true;
    tmp.push_back(v);
    for (auto& i : adj[v])
    {
        dfs(i);
    }
}

int main()
{
    int edges;
    cin >> edges;
    int nodes = -1;
    while (edges--)
    {
        int x, y;
        cin >> x >> y;
        nodes = max(nodes, max(x, y));
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= nodes; i++)
    {
        if (!visited[i]) 
        {
            dfs(i);
            connected.push_back(tmp);
            tmp.clear();
        }
    }
    for (auto& v : connected)
    {
        for (auto& i : v) cout << i << ' ';
        cout << '\n';
    }
}
