//
//  main.cpp
//  hashTable
//
//  Created by Anton on 2/27/18.
//  Copyright © 2018 Anton. All rights reserved.
//

#include <iostream>
#include <cstdio>

using namespace std;

bool find(int *arr, int n, int data) {
    for (unsigned int i = 0; i < n; i++)
        if (arr[i] == data)
            return true;
    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int m, n, c;
    cin >> m >> c >> n;
    int *hTable = new int[m];
    for (unsigned int i = 0; i < m; i++)
        hTable[i] = -1;
    for (unsigned int i = 0; i < n; i++) {
        int data = 0;
        cin >> data;
        if (!find(hTable, m, data)) {
            unsigned int k = 0;
            unsigned int h = ((data % m) + c*k) % m;
            while (hTable[h] != -1) {
                k++;
                h = ((data % m) + c*k) % m;
            }
            hTable[h] = data;
        }
    }
    
    cout << hTable[0];
    for (unsigned int i = 1; i < m; i++)
        cout << ' ' << hTable[i];
    delete[] hTable;
    return 0;
}
