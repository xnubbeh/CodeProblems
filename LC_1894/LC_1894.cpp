// LC_1894.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        unsigned int sum_chalk = 0;
        for(int c : chalk)
        {
            sum_chalk += c;
        }

        int remaining = k % sum_chalk;

        for (int index = 0; index < chalk.size(); index) {
            if (remaining - chalk[index] < 0) {
                return index;
            }
            remaining -= chalk[index];
        }
        return -1;
    }
};

int main()
{
    Solution sol;

    vector<int> chalk = { 3,4,1,2 };
    int k = 25;
    
    sol.chalkReplacer(chalk, k);
}

