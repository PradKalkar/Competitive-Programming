//This is a code for topological sort(using dfs)
//This is useful for job scheduling
#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > graph;
vector<bool> visited;
vector<int> order;

void dfs(int node)
{
    visited[node] = true;
    for (auto child : graph[node])
    {
        if (visited[child]) continue;
        dfs(child);
        order.push_back(child);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    // the vertices are labelled from 0 to n-1
    //n is the number of vertices and m is the number of edges which is the standard notation
    //input is a DAG(directed acyclic graph)
    graph = vector<vector<int> >(n);
    visited = vector<bool>(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        //graph[v].push_back(u); commenting this line since this is a directed graph
    }
    for (int i = 0; i < n; i++)
    {
        if (visited[i]) continue;
        dfs(i);
        order.push_back(i);
    }
    //order stores the order in which dfs of the vertices is finished completely
    //dfs(order[i]) finishes before dfs(order[i+1])
    reverse(order.begin(), order.end());
    cout << "The order in which the jobs to be performed is as follows: \n";
    for (auto i : order)
    {
        cout << i << ' ';
    }
    cout << '\n';
}

//eg test set
/*
9 8
0 1
2 1
2 3
3 4
4 5
7 3
7 6
6 5
 */
