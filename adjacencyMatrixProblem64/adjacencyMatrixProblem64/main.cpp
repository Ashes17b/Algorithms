//
//  main.cpp
//  adjacencyMatrixProblem64
//
//  Created by Anton on 2/20/18.
//  Copyright © 2018 Anton. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

class AdjacencyMatrix
{
private:
    unsigned int size;
    unsigned int **adj;
public:
    AdjacencyMatrix(int n) {
        this->size = n;
        adj = new unsigned int*[n];
        for (unsigned int i = 0; i < n; i++) {
            adj[i] = new unsigned int[n];
            for(unsigned int j = 0; j < n; j++)
                adj[i][j] = 0;
        }
    }
    void add_edge(unsigned int origin,unsigned int destin) {
        adj[origin - 1][destin - 1] = 1;
        adj[destin - 1][origin - 1] = 1;
    }
    void print() {
        for(unsigned int i = 0; i < size; i++) {
            for(unsigned int j = 0; j < size; j++)
                cout << adj[i][j] << ' ';
            cout << endl;
        }
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    unsigned int nodes, max_edges, origin, destin;
    cin >> nodes >> max_edges;
    AdjacencyMatrix am(nodes);
    for (unsigned int i = 0; i < max_edges; i++) {
        cin >> origin >> destin;
        am.add_edge(origin, destin);
    }
    am.print();
    return 0;
}
