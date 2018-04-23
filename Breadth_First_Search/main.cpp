//
//  main.cpp
//  breadthFirstSearch
//
//  Created by Anton on 3/6/18.
//  Copyright © 2018 Anton. All rights reserved.
//

#include <iostream>
#include <list>

using namespace std;

class Graph {
    unsigned int V;
    list<unsigned int> *adj;
    unsigned int *result;
    bool *visited;
    unsigned int index;
    unsigned int k = 1;
public:
    Graph(unsigned int V);
    ~Graph();
    void addEdge(unsigned int v, unsigned int w);
    void BFS(unsigned int s);
    void print();
    bool check();
};

Graph::Graph(unsigned int V) {
    this->V = V;
    adj = new list<unsigned int>[V];
    result = new unsigned int[V];
    for (unsigned int i = 0; i < V; i++)
        result[i] = -1;
    index = 0;
    for (unsigned int i = 0; i < V; i++)
        for (unsigned int j = 0; j < V; j++) {
            unsigned int data = 0;
            cin >> data;
            if (data)
                this->addEdge(i, j);
        }
    
    visited = new bool[V];
    for(unsigned int i = 0; i < V; i++)
        visited[i] = false;
}

Graph::~Graph() {
    delete[] result;
    delete[] adj;
    delete[] visited;
}

void Graph::addEdge(unsigned int v, unsigned int w) {
    adj[v].push_back(w);
}

bool Graph::check() {
    for (unsigned int i = 0; i < V; i++)
        if (result[i] == -1) {
            index = i;
            return true;
        }
    return false;
}

void Graph::BFS(unsigned int s) {
    list<unsigned int> queue;
    visited[s] = true;
    queue.push_back(s);
    while(!queue.empty()) {
        s = queue.front();
        result[s] = k;
        queue.pop_front();
        list<unsigned int>::iterator i = adj[s].begin();
        while(i != adj[s].end()) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
            ++i;
        }
        k++;
    }
    if (check())
        BFS(index);
}

void Graph::print() {
    cout << result[0];
    for (unsigned int i = 1; i < V; i++)
        cout << ' ' << result[i];
    cout << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    unsigned int n;
    cin >> n;
    Graph g(n);
    g.BFS(0);
    g.print();
    
    return 0;
}
