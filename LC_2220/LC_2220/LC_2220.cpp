// LC_2220.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int flips = start ^ goal;

        unsigned int min_flips = 0;
        while (flips) {
            min_flips += flips & 1;
            flips >>= 1;
        }

        cout << min_flips << endl;
        return min_flips;
    }
};

int main()
{
    Solution sol;

    int start = 3;
    int goal = 4;

    sol.minBitFlips(start, goal);

}


