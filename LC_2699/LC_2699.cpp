// LC_2699.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>

#define K_MAX 2'000'000'000
using namespace std;

typedef pair<int, int> int_pair;


class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& edge : edges) {
            const int u = edge[0];
            const int v = edge[1];
            const int w = edge[2];
            if (w == -1)
                continue;
            graph[u].emplace_back(v, w);
            graph[u].emplace_back(u, w);
        }
        int dist2dest = Solution::dijkstra(graph, source, destination);
        if (dist2dest < target) {
            return{};
        }

        //there alrdy is a path and we don't need to change anything
        if (dist2dest == target) {
            for (vector<int>& edge : edges) 
                if (edge[2] == -1) {
                    edge[2] = K_MAX;
                }
            
            return edges;
        }

        for (int i = 0; i < edges.size(); ++i) {
            const int u = edges[i][0];
            const int v = edges[i][1];
            int& w = edges[i][2];
            if (w != -1)
                continue;
            w = 1;
            graph[u].emplace_back(v, 1);
            graph[v].emplace_back(u, 1);
            dist2dest = dijkstra(graph, source, destination);
            if (dist2dest <= target) {
                w += target - dist2dest;
                //this is leftover change them to whatever
                for (int j = i + 1; j < edges.size(); ++j) {
                    if (edges[j][2] == -1) {
                        edges[j][2] = K_MAX;
                    }
                }
                return edges;
            }
        }

        return {};
    }



private:
    int dijkstra(vector<vector<pair<int, int>>>& graph, int source, int destination) {
        //make prio queue (min_heap)
        priority_queue<int_pair, vector<int_pair>, greater<>> pq;
        //init all the distances to infinity
        vector<int> dist(graph.size(), INT_MAX);

        //we can get to the source for free from the source
        dist[source] = 0;
        //put the shortest path in the prio queue
        pq.emplace(dist[source], source);

        //while we have stuff in the prio queue keep going 
        while (!pq.empty()) {
            //d = current distance
            //u = current node
            auto [d, u] = pq.top();
            pq.pop();
            //if a shorter distance to U has been found we skip the processes
            if (d > dist[u])
                continue;
            //look at through the neighbours of V of current node U
            for (const auto& [v, w] : graph[u])
                //check if the distance V to U is shorter than current known distance 
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.emplace(dist[v], v);
                }


        }
        return dist[destination];
    }

};
    
int main()
{
    int n = 4;
    vector<vector<int>> edges = { {1,0,4},{0,3,-1},{1,2,3},{2,3,5} };
    int source = 0;
    int destination = 2;
    int target = 6;

    /*int n = 4;
    vector<vector<int>> edges = { {2,1,5},{0,1,3},{0,3,-1},{2,3,9} };
    int source = 0;
    int destination = 2;
    int target = 9;*/

    Solution sol;
    sol.modifiedGraphEdges(n, edges, source, destination, target);
}
