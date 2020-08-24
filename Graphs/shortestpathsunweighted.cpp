//given an unweighted graph find the shortest path from the start vertex to every other vertex in linear time
//using bfs
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    //n is the number of vertices and m the number of edges
    cin >> n >> m;
    vector<int> graph[n];
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<bool> visited(n);
    queue<int> bfs;
    int start;
    cin >> start;
    bfs.push(start);
    vector<int> dist(n, INT32_MAX);
    dist[start] = 0;
    while (!bfs.empty())
    {
        int node = bfs.front();
        bfs.pop();
        visited[node] = true;
        for (auto i : graph[node]) {
            if (visited[i]) continue;
            dist[i] = min(dist[i], dist[node]+1);
            bfs.push(i);
        }
    }
    for (int i = 0; i < n; i++) cout << dist[i] << ' ';
    cout << '\n';
}
