//
//  main.cpp
//  ZamokProblem23
//
//  Created by Anton on 3/11/18.
//  Copyright © 2018 Anton. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct RoomSide {
    unsigned int west = 1;
    unsigned int north = 2;
    unsigned int east = 4;
    unsigned int south = 8;
};

class Castle {
private:
    /* Task Input */
    vector< vector<unsigned long> > visualCastle;
    vector< vector<unsigned long> > rooms;
    unsigned long m;
    unsigned long n;
    /* Variable for Solution */
    RoomSide roomSide;
    unsigned long k = 1;
    unsigned long roomCount = 0;
    unsigned long roomWithMaxSquare = 0;
    unsigned long roomWithMaxSquareAfterDelSide = 0;
public:
    Castle() {
        cin >> m >> n;
        for(unsigned long i = 0; i < m; i++) {
            vector<unsigned long> lineData;
            vector<unsigned long> zeros;
            for(unsigned long j = 0; j < n; j++) {
                unsigned long data = 0;
                zeros.push_back(data);
                cin >> data;
                lineData.push_back(data);
            }
            visualCastle.push_back(lineData);
            rooms.push_back(zeros);
        }
    
        
    }
    ~Castle() {}
    
    unsigned long createRoom(long i, long j) {
        if (rooms[i][j])
            return 0;
        
        rooms[i][j] = k;
        unsigned long square = 1;
        if (!(visualCastle[i][j] & roomSide.west) && j - 1 >= 0)
            square += createRoom(i, j - 1);
        if (!(visualCastle[i][j] & roomSide.north) && i - 1 >= 0)
            square += createRoom(i - 1, j);
        if (!(visualCastle[i][j] & roomSide.east) && j + 1 < n)
            square += createRoom(i, j + 1);
        if (!(visualCastle[i][j] & roomSide.south) && i + 1 < m)
            square += createRoom(i + 1, j);
        
        return square;
    }
    
    void solution() {
        vector<unsigned long> squares;
        for(long i = 0; i < m; i++)
            for(long j = 0; j < n; j++)
                if(!rooms[i][j]) {
                    squares.push_back(createRoom(i, j));
                    k++;
                }
        
        roomCount = squares.size();
        roomWithMaxSquare = *max_element(squares.begin(), squares.end());
        roomWithMaxSquareAfterDelSide = roomWithMaxSquare;
        /* Find Side for delete */
        for (unsigned long i = 0; i < m; i++) {
            for (unsigned long j = 0; j < n; j++) {
                if (j < n - 1 && (visualCastle[i][j] & roomSide.east))
                    if (rooms[i][j] != rooms[i][j + 1] && squares[rooms[i][j] - 1] +
                        squares[rooms[i][j + 1] - 1] > roomWithMaxSquareAfterDelSide)
                        roomWithMaxSquareAfterDelSide = squares[rooms[i][j] - 1] + squares[rooms[i][j + 1] - 1];
                
                if (i < m - 1 && (visualCastle[i][j] & roomSide.south))
                    if (rooms[i][j] != rooms[i + 1][j] && squares[rooms[i][j] - 1] +
                        squares[rooms[i + 1][j] - 1] > roomWithMaxSquareAfterDelSide)
                            roomWithMaxSquareAfterDelSide = squares[rooms[i][j] - 1] + squares[rooms[i + 1][j] - 1];
            }
        }
    }
    
    void outputSolution() {
        cout << roomCount << endl;
        cout << roomWithMaxSquare << endl;
        cout << roomWithMaxSquareAfterDelSide << endl;
    }
};

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    
    /* Fast input */
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Castle castle;
    castle.solution();
    castle.outputSolution();
    
    return 0;
}
