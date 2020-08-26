//This program implements edge classification using dfs
//This program also does cycle detection using edge classification
//The tree edges actually form a tree or a forest if there are many
//This program is typically for a directed graph
//In undirected graph, there are only two types of edges, backward and tree
#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;
vector<bool> visited;
vector<int> component;
vector<int> level;
map<pair<int, int>, string> edgetype; //tree edge,forward edge(node to descendant), backward edge(node to ancestor), cross edges(remaining all are cross)
int n, m;
int cnt = 0;

void dfs_component(int node) //explore the parts of the graph reachable through the node
{
    visited[node] = true;
    component[node] = cnt;
    for (auto child : adj[node])
    {
        if (visited[child])
        {
            if (component[node] == component[child])
            {
                if (level[node] > level[child])
                {
                    edgetype[{node, child}] = "backward";
                }
                else if (level[node] < level[child])
                {
                    edgetype[{node, child}] = "forward";
                }
                else
                {
                    //its a cross edge
                    //cross edge is a edge connecting two vertices which belong to the tree and are at same level
                    //or the edge which connects two different trees in a forest
                }
            }
            continue;
        }
        edgetype[{node, child}] = "tree";
        level[child] = level[node]+1;
        dfs_component(child);
    }
}

void dfs_complete() //explore the whole graph : Time complexity is theta(n+m)
{
    for (int i = 0; i < n; i++)
    {
        if (visited[i]) continue;
        //visit all the parts reachable from the vertex i
        cnt++;
        dfs_component(i);
    }
}

int main()
{
    cin >> n >> m;
    //n is the number of vertices and m is the number of edges
    //vertices are numbered from 0 to n-1
    //take the edges as input
    visited = vector<bool>(n);
    adj = vector<vector<int> >(n);
    level = component = vector<int>(n);
    string s;
    cout << "Specify the type of the graph (directed or undirected): ";
    cin >> s;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edgetype[{u, v}] = "cross";
        adj[u].push_back(v);
        if (s == "undirected")
            adj[v].push_back(u);
    }
    dfs_complete();
    for (int i = 0; i < n; i++)
    {
        cout << "Vertex " << i << ": " << ((visited[i]) ? "visited\n" : "not visited\n");
    }
    cout << '\n';
    cout << "The number of connected components are " << cnt << '\n';
    cout << "The components corresponding to individual vertices are: \n";
    for (auto i : component) cout << i << ' ';
    cout << '\n';
    cout << "The vertices having same components are connected together\n";
    cout << "The edge types are as follows: \n";
    bool cycle = false;
    for (auto& [edge, type] : edgetype)
    {
        if (type == "forward" && s == "undirected") continue;
        if (edgetype.count({edge.second, edge.first}))
        {
            if (edgetype[{edge.second, edge.first}] == "tree") continue;
        }
        cout << edge.first << "->" << edge.second << " "+type+"\n";
        if (type == "backward")
        {
            cycle = true;
        }
    }
    if (cycle)
    {
        cout << "There exists a cycle in the graph\n";
    }
    else
    {
        cout << "There doesn't exists a cycle in the graph\n";
    }
    //for an undirected graph the possible edge types are only backward and tree
}
