//
//  main.cpp
//  DijkstraWithLength
//
//  Created by Anton on 3/24/18.
//  Copyright © 2018 Anton. All rights reserved.
//

#include <iostream>
#include <vector>
#include <limits>
#include <set>

using namespace std;

struct edge {unsigned long to, length; };
void addEdge(vector< vector<edge> > &graph, unsigned long u, unsigned long v, unsigned long len) {
    edge e1, e2;
    e1.to = v; e1.length = len;
    e2.to = u; e2.length = len;
    graph[u].push_back(e1);
    graph[v].push_back(e2);
}

unsigned long dijkstra(const vector< vector<edge> > &graph) {
    vector<unsigned long> min_distance( graph.size(), numeric_limits<unsigned long>::max() );
    min_distance[0] = 0;
    set< pair<unsigned long, unsigned long> > active_vertices;
    active_vertices.insert( {0,0} );
    
    while (!active_vertices.empty()) {
        unsigned long where = active_vertices.begin()->second;
        if (where == graph.size() - 1)
            return min_distance[where];
        active_vertices.erase( active_vertices.begin() );
        for (const auto &edge : graph[where])
            if (min_distance[edge.to] > min_distance[where] + edge.length) {
                active_vertices.erase( { min_distance[edge.to], edge.to } );
                min_distance[edge.to] = min_distance[where] + edge.length;
                active_vertices.insert( { min_distance[edge.to], edge.to } );
            }
    }
    
    return numeric_limits<unsigned long>::max();
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    unsigned long n, m;
    cin >> n >> m;
    
    vector< vector<edge> > graph(n);
    unsigned long u, v, len;
    for (unsigned long i = 0; i < m; i++) {
        cin >> u >> v >> len;
        addEdge(graph, u - 1, v - 1, len);
    }
    
    cout << dijkstra(graph) << endl;
    return 0;
}
