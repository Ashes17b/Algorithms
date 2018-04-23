//
//  main.cpp
//  buildGraphAdjMatrix
//
//  Created by Anton on 3/6/18.
//  Copyright © 2018 Anton. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    unsigned int n = 0;
    cin >> n;
    unsigned int **adjMatrix = new unsigned int*[n];
    for (unsigned int i = 0; i < n; i++)
        adjMatrix[i] = new unsigned int[n];
    
    unsigned int *p = new unsigned int[n];
    for (unsigned int i = 0; i < n; i++)
        p[i] = 0;
    for (unsigned int i = 0; i < n; i++)
        for (unsigned int j = 0; j < n; j++) {
            cin >> adjMatrix[i][j];
            if (adjMatrix[i][j] != 0)
                p[j] = i + 1;
        }
    
    cout << p[0];
    for (unsigned int i = 1; i < n; i++)
        cout << ' ' << p[i];
    

    for (unsigned int i = 0; i < n; i++)
        delete[] adjMatrix[i];
    delete[] adjMatrix;
    delete[] p;
    return 0;
}
