pseudocode for dijkstra:
suppose we need to find the length of the shortest paths from x to all the vertices
let the vertices be numbered from 1 to n

dijkstra(x):
    for (int i = 1; i <= n; i++){
        sp[i] = INF;
    }

    d[x] = 0

    priority_queue<pii> q;  //every element of the queue is of the form {-d[vert], vert} where d[vert] is the 
                            //current sp distance from x to vert

    vb visited(n, false)
    int no_of_visited = 0

    q.push({0, x})
    while (no_of_visited != n){
        //at each step we do a extract min op and if the vertex we extract is not visited, then we have achieved 
        //d[vert] = sp(x, vert)
        
        int a = q.top().second;
        q.pop();
        if (visited[a]) continue;

        visited[a] = true
        no_of_visited++;
        //now we have got the d[a] converged to sp(x, a)

        for (auto [b, w] : grh[a]){
            //relax the edge (a, b)
            if (d[a] + w < d[b]){
                d[b] = d[a] + w
                q.push({-d[b], b});
            }
        }
    }
