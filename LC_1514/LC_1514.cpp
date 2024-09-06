// LC_1514.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> G(n);
        for (int i = 0; i < succProb.size(); ++i) {
            const int u = edges[i][0];
            const int v = edges[i][1];
            const double p = succProb[i];

            G[u].emplace_back(v, p);
            G[v].emplace_back(u, p);
        }
        double prob2dest = dijkstra(G, start_node, end_node);
        
        return prob2dest;
    }

    double dijkstra(vector<vector<pair<int,double>>>& G, int start_node, int end_node) {
        using prob_pair = pair<double, int>;
        priority_queue<prob_pair> pq;
        vector<double> prob(G.size(), 0.0);
        prob[start_node] = 1.0;
        pq.emplace(prob[start_node],start_node);

        while (!pq.empty()) {
            auto [curr_Prob, curr_Node] = pq.top();
            pq.pop();

            if (curr_Prob < prob[curr_Node]) continue;

            for (const auto& [next_Node, next_Prob] : G[curr_Node]) {
                if (curr_Prob * next_Prob > prob[next_Node]) {
                    prob[next_Node] = curr_Prob * next_Prob;
                    pq.emplace(prob[next_Node], next_Node);
                }
            }
        }
        return prob[end_node];
    }

};


int main()
{
    int n = 3;
    vector<vector<int>> edges = { {0,1},{1,2},{0,2} };
    vector<double> succProb = { 0.5,0.5,0.2 };
    int start = 0;
    int end = 2;

    Solution sol;
    sol.maxProbability(n, edges, succProb, start, end);


    return 0;
}


