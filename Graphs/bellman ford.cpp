// Bellmann ford algo for computing the shortest path distances from src to any vertex i
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    // direted graph
    // bellman ford

    cin >> n >> m;
    // n nodes from 0 to n-1
    vector<tuple<int, int, int> > edge_list;
    for (int i = 0; i < m; i++){
        int src, dest, wt;
        cin >> src >> dest >> wt;
        edge_list.push_back({src, dest, wt});
    }

    // algo starts
    vector<int> sp(n, INT_MAX); // sp[i] - sp distance from src to i
    vector<int> first(n, -1); // for the pointer graph for retracing the sp
    int src;
    cin >> src;

    sp[src] = 0;
    for (int i = 1; i <= n-1; i++){
        for (auto& [a, b, w]: edge_list){
            if (sp[a] != INT_MAX && sp[a]+w < sp[b]){
                sp[b] = sp[a]+w;
                first[b] = a;
            }
        }
    }
    // here are all the shortest path distances assuming no negative cycle
    for (int i = 0; i < n; i++){
        cout << i << ": " << sp[i] << '\n'; 
    }

    // now detect the presence of the negative edge cycle
    // if the sp can further be reduced, then there exists a negative edge cycle

    for (auto& [a, b, w]: edge_list){
        if (sp[a] != INT_MAX && sp[a]+w < sp[b]){
            cout << "Negative cycle found\n";
            break;
        }
    }
}