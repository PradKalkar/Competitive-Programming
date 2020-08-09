#include <bits/stdc++.h>
using namespace std;
#define N 1000

vector<int> adj[N];
bool visited[N];
bool color[N]; //color[i] = true if ith vertex is colored red
bool bipartite = true;

void dfs(int v)
{
    visited[v] = true;
    for (auto i : adj[v])
    {
        if (!visited[i])
        {
            color[i] = !color[v];
            dfs(i);
        }
        else
        {
            if (color[i] == color[v])
            {
                bipartite = false;
            }   
        }
    }
}

int main()
{
    int edges;
    cin >> edges;
    while (edges--)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    //assuming that the graph is connected
    color[1] = 1;
    dfs(1);
    if (bipartite)
    {
        cout << "The given graph is bipartite\n";
    }
    else
    {
        cout << "The given graph is not bipartite\n";
    }
}
