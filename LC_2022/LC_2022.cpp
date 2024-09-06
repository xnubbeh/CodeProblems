// LC_2022.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int product = m * n;
        vector<vector<int>> ans(m);
        int line = 0;

        if (original.size() % product != 0 || original.size() > product) {
            return {};
        }

        for (int i = 0; i < original.size(); ++i) {
            if (i % n == 0 && i != 0) {
                line++;
            }
            ans[line].push_back(original[i]);
        }
        return ans;
    }
};

int main()
{
    vector<int> original = { 5,5,3,5,4,5,4,3,2,2,5,4 };
    int m = 3;
    int n = 2;

    Solution sol;
    sol.construct2DArray(original, m, n);
}

