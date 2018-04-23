//
//  main.cpp
//  buildGraph
//
//  Created by Anton on 3/1/18.
//  Copyright © 2018 Anton. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <list>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    unsigned int n = 0;
    cin >> n;
    list<unsigned int> *adjList = new list<unsigned int>[n];
    for (unsigned int i = 0; i < n; i++)
        adjList[i].push_back(i + 1);
    unsigned u, v;
    for (unsigned int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adjList[u - 1].push_back(v);
    }
    
    
    unsigned int *p = new unsigned int[n];
    for (unsigned int i = 0; i < n; i++)
        p[i] = 0;
    for (unsigned int i = 0; i < n; i++) {
        list<unsigned int>::iterator it = adjList[i].begin();
        ++it;
        while(it != adjList[i].end()) {
            p[*it - 1] = *adjList[i].begin();
            ++it;
        }
    }
    
    cout << p[0];
    for (unsigned int i = 1; i < n; i++)
        cout << ' ' << p[i];
    
    delete[] p;
    delete[] adjList;
    return 0;
}


