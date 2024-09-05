// LC_874.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <iterator>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<pair<int, int>, hash_pair> obstacleSet = convertToSet(obstacles);
        int x = 0, y = 0;  // Starting position
        int direction = 0; // North = 0, East = 1, South = 2, West = 3
        int maxDistance = 0;
        // Directions array represents [dx, dy] for North, East, South, West
        vector<vector<int>> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

        for (int command : commands) {
            if (command == -1) { // Turn right
                direction = (direction + 1) % 4;
            }
            else if (command == -2) { // Turn left
                direction = (direction -1 + 4) % 4; 
            }
            else {
                for (int i = 0; i < command; ++i) {
                    int nx = x + directions[direction][0];
                    int ny = y + directions[direction][1];

                    if (obstacleSet.find({ nx, ny }) != obstacleSet.end()) {
                        break; // Stop if there is an obstacle
                    }

                    x = nx;
                    y = ny;
                    maxDistance = max(maxDistance, x * x + y * y);
                }
            }
        }  
        return maxDistance; // Distance squared from the origin
    }


    //I didn't come up with this
    struct hash_pair {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);
            return hash1 ^ hash2; // Combine two hash values
        }
    };

    unordered_set<pair<int,int>,hash_pair> convertToSet(const vector<vector<int>>& obstacles) {
        unordered_set<pair<int, int>, hash_pair> obstacleSet;
        for (const auto& obstacle : obstacles) {
            obstacleSet.emplace(obstacle[0], obstacle[1]);
        }
        return obstacleSet;
    }   

};

int main()
{
    Solution sol;

    vector<int> commands = { 6, -1,-1, 6 };
    vector<vector<int>> obstacles = { };

    sol.robotSim(commands, obstacles);
    return 0;
}
