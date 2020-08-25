#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    //n is the number of vertices and m is the number of edges
    vector<vector<int> > adj(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> parent(n), level(n, -1);
    queue<int> bfs;
    int start;
    cin >> start;
    bfs.push(start);
    parent[start] = -1, level[start] = 0;
    while (!bfs.empty())
    {
        int node = bfs.front();
        bfs.pop();
        for (auto i : adj[node])
        {
            if (level[i] != -1) continue; //implies that u have already visited i

            level[i] = level[node]+1;
            parent[i] = node;
            bfs.push(i);
        }
    }
    //enter the destination for which u wanna find the shortest path to
    int dest;
    cin >> dest;
    cout << "The length of the shortest path is " << level[dest] << '\n';
    //now printing the shortest path using backtracking the parent pointers
    vector<int> path;
    int x = dest;
    while (x != -1)
    {
        path.push_back(x);
        x = parent[x];
    }
    reverse(path.begin(), path.end());
    cout << "One of the shortest paths is ";
    for (auto i : path) cout << i << ' ';
    cout << '\n';
}
