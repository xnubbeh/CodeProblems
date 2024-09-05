#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, vector<int>> graph;
        int connected = 0;

        if (stones.size() == 0) {
            return 0;
        }

        for (int i = 0; i < stones.size(); i++) {
            for (int j = i + 1; j < stones.size(); j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                    connected++;
                }               
            }
        }
        
        unordered_set<int> visited;
        int counter = 0;

        for (int x = 0; x < stones.size(); x++) {
            if (visited.find(x) == visited.end()) {
                dfs(x, graph, visited);
                counter++;
            }
        }

        cout << "CONNECTED: " << connected << std::endl;
        cout << "COUNTER: " << counter << std::endl;
        cout << "SIZE: " << stones.size() << std::endl;
        return stones.size() - counter;

    }

    void dfs(int index, unordered_map<int,vector<int>>& graph, unordered_set<int>& visited) {
        visited.insert(index);
        for (int n : graph[index]) {
            if (visited.find(n) == visited.end()) {
                dfs(n, graph, visited);
            }
        }
    }



};

int main() {
    Solution sol;
    //vector<vector<int>> stones = { {0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2} };
    //vector<vector<int>> stones = { {0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2} };
    vector<vector<int>> stones = { {0, 0}, {2, 2} };
    //vector<vector<int>> stones = { {0, 1}, {1, 0}, {1,1} };
    sol.removeStones(stones);
    return 0;
}