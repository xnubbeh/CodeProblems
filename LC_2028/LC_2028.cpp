// LC_2028.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sumRolls = 0;
        vector<int> ans;
        for (int roll : rolls) {
            sumRolls += roll;
        }
        int x = mean * (rolls.size() + n) - sumRolls;
        if (x > (n * 6)) {
            cout << "impossible mean is too high" << endl;
            return {};
        }
        if (x < n) {
            cout << "impossible mean is too low" << endl;
            return {};
        }

        //now I need to split X into N parts
        if (x % n == 0) {
            int even_split = x / n;
            for (int i = 0; i < n; i++) {
                ans.push_back(even_split);
            }
            return ans;
        }
        else {
            int leftOver = x % n;
            //remove the left over to put in the even splits
            int even_split = (x - leftOver) / n;
            for (int i = 0; i < n; i++) {
                if (leftOver != 0) {
                    int room = 6 - even_split;
                    if (room < leftOver) {
                        ans.push_back(even_split + room);
                        leftOver -= room;
                    }
                    else {
                        ans.push_back(even_split +leftOver);
                        leftOver = 0;
                    }
                }
                else {
                    ans.push_back(even_split);
                }
            }
            //now we need to add the leftover
            // how much can I add then remove that much from leftover and add the rest to the next even_split
            // room left is just 6 - even_split 
            return ans;
        }
        return {};
    }
};

int main()
{
    Solution sol;

    vector<int> rolls = {1,5,6};
    int mean = 3;
    int n = 4;

    sol.missingRolls(rolls, mean, n);

    return 0;
}
