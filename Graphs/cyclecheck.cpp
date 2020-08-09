/*A graph contains a cycle if during a graph traversal, we find a node whose
neighbor (other than the previous node in the current path) has already been
visited*/
//i.e for a given node v if all the child nodes have been visited and their no. is greater than 2, then the cycle 
//is detected
#include <bits/stdc++.h>
using namespace std;
#define N 1000

bool cycle = false;
bool visited[N];
vector<int> adj[N];

void dfs(int v)
{
    if (visited[v]) return;
    visited[v] = true;
    bool done = true;
    int cnt = 0;
    for (auto i : adj[v])
    {
        //if visited[i] = true for all i then cycle is detected
        if (visited[i]) 
        {
            cnt++;
            continue;
        }
        done = false;
        dfs(i);
    }
    if (done && cnt > 1)
        cycle = true;
}

int main()
{
    int edges;
    cin >> edges;
    while (edges--)
    {
        int x, y;
        cin >>  x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    //nodes are numbered starting from 1
    dfs(1);
    if (cycle)
        cout << "Yes";
    else
    {
        cout << "No";
    } 
}
