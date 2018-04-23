//
//  main.cpp
//  adjList
//
//  Created by Anton on 2/27/18.
//  Copyright © 2018 Anton. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <list>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    unsigned int nodes, edges, origin, destin;
    cin >> nodes >> edges;
    list<unsigned int> *adjList = new list<unsigned int>[nodes];
    for (unsigned int i = 0; i < nodes; i++)
        adjList[i].push_back(i + 1);
    for (unsigned int i = 0; i < edges; i++) {
        cin >> origin >> destin;
        adjList[origin - 1].push_back(destin);
        adjList[destin - 1].push_back(origin);
    }
    
    for (unsigned int i = 0; i < nodes; i++) {
        cout << adjList[i].size() - 1;
        list<unsigned int>::iterator it = adjList[i].end();
        --it;
        while (it != adjList[i].begin()) {
            cout << ' ' << *it;
            --it;
        }
        cout << endl;
    }
    delete[] adjList;
    return 0;
}
